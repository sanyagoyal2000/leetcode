class Solution {
  int helper(int idx, vector<int> &coins, int sum, int &target, vector<vector<int>> &dp){
    if(idx==coins.size()) return 0;
    int ans=0;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    if(sum+coins[idx]==target) return dp[idx][sum]=1;
    else if(sum+coins[idx]<target)
      ans += helper(idx, coins, sum+coins[idx], target, dp);
    ans += helper(idx+1, coins, sum, target, dp);
    return dp[idx][sum]=ans;
  }
public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
    if(amount==0) return 1;
    return helper(0, coins, 0, amount, dp);
  }
};

/*

  int recur(int amount, vector<int>& coins, int ind, vector<vector<int>> dp) {
    if(amount==0){
      return  1;
    }
    if(amount<0)
        return 0;
    
    if(ind<0 || ind>=coins.size())
        return 0;
    int a = recur(amount-coins[ind], coins, ind,dp);
   
    int b = recur(amount, coins, ind+1,dp);

    return  a+b ;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size(),i,j,count;
    vector<vector<int>> dp(n+2, vector<int>(amount+2,0));
    
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(i=1; i<=n;i++) {
        for(j=1;j<=amount;j++) {
            if(coins[i-1]<=j) {
           
                dp[i][j]= (dp[i][j-coins[i-1]] + dp[i-1][j]);
           
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return dp[n][amount];
}*/