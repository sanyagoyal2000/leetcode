class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>>hashmap(26);
        for(int i=0;i<26;++i)   hashmap[i].push_back(-1);
        for(int i=0;i<s.size();i++){
            int id=s[i]-'A';
            hashmap[id].push_back(i);
        }
        for(int i=0;i<26;i++){
            hashmap[i].push_back(s.size());
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            for(int j=1;j<hashmap[i].size()-1;j++){
                cnt+=(hashmap[i][j]-hashmap[i][j-1])*(hashmap[i][j+1]-hashmap[i][j]);
            }
        }
        return cnt;
    }
};