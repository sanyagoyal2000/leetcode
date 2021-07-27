class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     
vector<int>ans(2,-1);
     int n=nums.size();
        if(n==0 or nums[n-1]<target)return ans;
     auto it1=lower_bound(nums.begin(),nums.end(),target);
     auto it2=upper_bound(nums.begin(),nums.end(),target);
      
      int k=nums[it1-nums.begin()];
        if(k!=target){
            return ans;
        }
      
      
          int p1=it1-nums.begin();
          int p2=it2 -nums.begin()-1;
          
              ans[0]=p1;
              ans[1]=p2;
          return ans;
}
};
