class Solution {
public:
    int MOD = 1e9+7;
    int dp[100001][3][2];
    
    long topDown(int n, int late, bool absent) {
        if(n <= 0){
            return 0;
        }
        if(n == 1){
            // Present
            int ans = 1;
            // Absent
            if(!absent) ans += 1;
            // Late
            if(late < 2) ans += 1;
            return ans;
        }
        
        if(dp[n][late][absent] != -1){
            return dp[n][late][absent];
        }
        
        // Present
        long total = topDown(n-1, 0, absent)%MOD;
        
        // Absent
        if(!absent){
            total = (total + (topDown(n-1, 0, true))%MOD)%MOD;
        }
        
        // Late
        if(late < 2){
            total = (total + (topDown(n-1, late+1, absent))%MOD)%MOD;
        }
        
        return dp[n][late][absent] = total;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return topDown(n, 0, false);
    }
};
