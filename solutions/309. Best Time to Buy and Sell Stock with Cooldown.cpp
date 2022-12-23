class Solution {
public:
    int helper(int i,bool buy,vector<int>prices,vector<vector<int>>dp){
        if(i>=prices.size())return 0;
        int profit=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy==true){
            //int take=helper(i+1,false,prices,dp)-prices[i];
            //int nottake=helper(i+1,true,prices,dp);
            return dp[i][buy]=max(helper(i+1,false,prices,dp)-prices[i],helper(i+1,true,prices,dp));
        }
        
            //int sell=prices[i]+helper(i+2,true,prices,dp);
            //int notsell=helper(i+1,false,prices,dp);
            return dp[i][buy]=max(prices[i]+helper(i+2,true,prices,dp),helper(i+1,false,prices,dp));
        
        
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1||prices.size()==0){
            return 0;
        }
        int n=prices.size();
       //vector<vector<int>> dp(n,vector<int>(2,-1));
        //return helper(0,true,prices,dp);
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    dp[i][buy]=max(dp[i+1][0]-prices[i],dp[i+1][1]);
                }
                else dp[i][buy]=max(dp[i+2][1]+prices[i],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};
