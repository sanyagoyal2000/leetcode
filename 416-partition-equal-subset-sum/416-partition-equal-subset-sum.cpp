class Solution {
public:
    bool help(vector<int>& nums,int sum,int i,vector<vector<int>> &dp)
    {
        if(i>=nums.size() || sum<0)
        {
            return false;
        }
        else if(dp[sum][i] != -1)
        {
            return dp[sum][i];
        }
        else if(sum == 0)
        {
            return true;
        }
        return dp[sum][i] = help(nums,sum-nums[i],i+1,dp)||help(nums,sum,i+1,dp);
    }
    

    
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum%2)
            return false;
        else
        {
            vector<vector<int>> dp((sum/2)+1,vector<int>(nums.size(),-1));
            return help(nums,sum/2,0,dp);
    
        }
    }
};