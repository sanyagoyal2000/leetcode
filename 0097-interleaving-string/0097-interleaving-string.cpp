class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      int m = s1.size(), n = s2.size();

        if(m + n != s3.size()) return false;

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for(int i = 1; i<=m && s3[i-1] == s1[i-1]; ++i) dp[i][0] = true;
        for(int j = 1; j<=n && s3[j-1] == s2[j-1]; ++j) dp[0][j] = true;

        for(int i =1; i<=m; i++)
        {
            for(int j = 1; j<=n; ++j)
            {
                if(s1[i-1] == s3[i+j-1]) dp[i][j] = dp[i][j] || dp[i-1][j];
                if(s2[j-1] == s3[i+j-1]) dp[i][j] = dp[i][j] || dp[i][j-1];
            }
        }

        return dp[m][n];  
    }
};