class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
         int n = nums.size();
        
        int dp[n+1][1005];
        memset(dp, 0, sizeof dp);
        
        int len = 2;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int diff = nums[j] - nums[i] + 500;
               
                dp[j][diff] = max(2, dp[i][diff]+1);
                
                len = max(len, dp[j][diff]);
            }
        }
        
        return len;
    }
};