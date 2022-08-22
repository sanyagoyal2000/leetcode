vector<int> directions {1,-1};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> seen;
        for(auto i: deadends) seen.insert(i);
        
        queue<string> q;
        q.push("0000");
        q.push("");
        
        int depth = 0;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            //If string is blank
            if(curr.empty()) {
                depth++;
                //If more things are in queue add blank string to denote new layer
                if(!q.empty()) q.push("");
            }
            else if(curr == target) return depth;
            else if(seen.find(curr) == seen.end()) {
                seen.insert(curr);
                for(int i = 0; i<4; i++) {
                    for(auto direction: directions) {
                        char curr_char = ((((curr[i] - '0') + direction) + 10) % 10) + '0';
                        string temp_curr = curr;
                        temp_curr[i] = curr_char;
                        q.push(temp_curr);
                    }
                }
            }
        }
        return -1;
    }
};