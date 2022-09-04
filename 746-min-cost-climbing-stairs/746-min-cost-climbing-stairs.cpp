class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int>dp(n);
    dp[0]=cost[0]; dp[1]=cost[1];
    for(int i=2;i<n;i++)
    {
        int x=cost[i]+dp[i-1];
        int y=cost[i]+dp[i-2];
        dp[i]=min(x,y);
    }
    return min(dp[n-1],dp[n-2]);
}
};