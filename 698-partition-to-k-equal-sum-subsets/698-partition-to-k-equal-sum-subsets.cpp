class Solution {
public:
   /* int dp[(1<<16)+2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }*/
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    
      int sum =accumulate(nums.begin(),nums.end(),0);
      vector<bool>vis(nums.size(),false);
      if(sum%k!=0)
        return false;
      int s=sum/k;
      sort(begin(nums),end(nums),greater<int>());// For avoid extra calculation
      return is_possible(nums,0,s,k,0,vis);
  }
 bool is_possible(vector<int>&nums,int curr,int sum,int k,int start,vector<bool>&vis)
{
        if(k==1)
            return true;
        if(start>=nums.size()) //This line is important to avoid tle
           return false;
        if(curr==sum)
                return is_possible(nums,0,sum,k-1,0,vis);
    
    for(int i=start;i<nums.size();i++)
    {
        if(vis[i] || nums[i]+curr>sum)
            continue;
        vis[i]=true;
        if(is_possible(nums,curr+nums[i],sum,k,i+1,vis))
            return true;
        vis[i]=false;
    }
    return false;
}
};