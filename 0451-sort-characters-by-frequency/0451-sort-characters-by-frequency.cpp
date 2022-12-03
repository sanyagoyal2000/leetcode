class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        set<int>pq;
        map<int,vector<char>>mp;
        for(auto ele:f){
            pq.insert(ele.second);
            mp[ele.second].push_back(ele.first);
        }
             
         
        string ans;
        while(!pq.empty()){
            int x=*pq.begin();
            for(auto ele:mp[x]){
                for(int i=0;i<x;i++){
                    ans+=ele;
                }
            }
            pq.erase(pq.begin());
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};