class Solution {
public:
    int solve(int i,int n,vector<int>&dp)
    {
        if(n==0)
            return 0;
        if(i*i>n)
            return INT_MAX-1;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=min(1+solve(i,n-i*i,dp),solve(i+1,n,dp));
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(1,n,dp);
    }
};
