class Solution {
public:
    
        
       int findPairs(vector<int>& nums, int k) {
        if(k<0){return 0;}
        unordered_map<int,int> mp;      
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
       int count = 0;
       for(auto x : mp){
           int diff = x.first - k;
           if(mp.find(diff)!=mp.end()){
               if(diff==x.first and x.second>1){
                   count++;
               }else if(diff!=x.first and x.second>=1){
                   count++;
               }
           }
       }
        return count;
       
    }
};