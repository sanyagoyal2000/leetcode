class Solution {
public:
    int dp[1001][2][101];
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=k;j++){
                if(i==n-1){
                    dp[i][0][j]=0;
                    dp[i][1][j]=(j>=1)?prices[i]:0;
                }
                else{
                    dp[i][0][j]=max(dp[i+1][1][j]-prices[i],dp[i+1][0][j]);
                    dp[i][1][j]=max((j>=1)?dp[i+1][0][j-1]+prices[i]:0,dp[i+1][1][j]);
                }
            }
        }
        return dp[0][0][k];
    }
};