class Solution {
public:
     map<string, vector<string>> nodes;
    vector<vector<string>> ans;
    void dfs(string & node, string & endWord, vector<string> & curr) {
        if (node == endWord) {
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        
        for (auto & child:nodes[node]) {
            curr.push_back(child);
            dfs(child, endWord, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // possible words
	    unordered_set<string> mp;
        for (string &w:wordList){
            mp.insert(w);
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        string last;
		
		// record the current step
        int step;
		
        int shortest_len = 1e9;
        int curr = 1;
        while(!q.empty()) {
            tie(last, step) = q.front(); q.pop();
			
			// if current step is started, then we can remove the already-visited words
            if (step == curr) {
                for (auto v:visited) {
                    mp.erase(v);
                }
                visited.clear();
                curr = step + 1;
                
				// If current step is at the shortest_answer_len, then we can stop finding
				// because we are going to find the shortest paths only.
                if (step >= shortest_len) {
                    break;
                }
            }
            
            for (int i = 0; i < (int)last.size(); ++i) {
                string t = last;
                for (char c = 'a'; c <='z'; ++c) {
				    // change the each index and check if it is in the wordlist.
                    t[i] = c;
                    if (c != last[i] && mp.count(t) > 0) {
					    // If possible, then we can save the path from destination to source
						// because we are going to traverse backward.
                        nodes[t].push_back(last);
						
						// If the word is already in the queue, then we don't need to add it again.
                        if (visited.count(t) == 0) {
                            visited.insert(t);
                            if (t == endWord) {
                                shortest_len = step;
                            } 
                            q.push({t, step+1});
                        }
                    }
                }
            }
        }
        
		
		// Find the answer backward.
        vector<string> arr;
        arr.push_back(endWord);
        dfs(endWord, beginWord, arr);
        
        return ans;
    }
};

