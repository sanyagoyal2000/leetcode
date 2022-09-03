class Solution {
	class TrieNode {
	public:
		bool is_end;
		string vocab;
		TrieNode* next[26];
		
		// constructor
		TrieNode() {
			for (int i = 0; i < 26; i++) {
				next[i] = nullptr;
			}
			is_end = false;
			vocab = "";
		}
	};

	TrieNode* root;
	
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		root = new TrieNode();
		// build prefix tree
		for (auto word: wordDict) {
			TrieNode* node = root;
			for (auto ch: word) {
				if (node->next[ch - 'a'] == nullptr) {
					node->next[ch - 'a'] = new TrieNode();
				}
				node = node->next[ch - 'a'];
			}
			node->is_end = true;
			node->vocab = word;
		}
		
		// start searching
		vector<string> ans;
		vector<int> visited(s.size());
		dfs(s, ans, 0, "", visited);

		return ans;
	}

	bool dfs(string& s, vector<string>& ans, int curr_idx, string curr, vector<int>& visited) {
		if (curr_idx >= s.size()) {
			// erase the leading whitespace
			curr.erase(0, 1);
			ans.push_back(curr);
			return true;
		}
		if (visited[curr_idx]) {
			return false;
		}
		TrieNode* node = root;

		bool flag = false;
		for (int i = curr_idx; i < s.size(); i++) {
			int target = s[i] - 'a';
			if (node->next[target] != nullptr) {
				node = node->next[target];
				if (node->is_end && dfs(s, ans, i + 1, curr + " " + node->vocab, visited)) {
					flag = true;
				}
			}
			else {
				break;
			}
		}
		
		// only when flag is false that we mark it as visited
		if (!flag) {
			visited[curr_idx] = 1;
		}
		return flag;  
	}
};