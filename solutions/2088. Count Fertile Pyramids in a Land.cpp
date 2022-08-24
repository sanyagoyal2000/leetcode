class Solution {
public:
    int solve(vector<vector<int>>& dp) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = dp.size(), n = dp[0].size(), sum = 0, i, j;
        for (i = 1; i < m; i++) {
            for (j = 1; j < n-1; j++) {
                if(dp[i][j] && dp[i-1][j]) {
                    dp[i][j] = 1+min(dp[i-1][j-1], dp[i-1][j+1]);
                    sum += dp[i][j]-1;
                }
            }
        }
        return sum;
    }
    
    int countPyramids(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>>dp1, dp2;
        dp1 = grid;
        dp2 = grid;
        reverse(dp1.begin(), dp1.end());
        return solve(dp1)+solve(dp2);
    }
};
