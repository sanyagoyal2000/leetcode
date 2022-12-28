class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string t=strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};