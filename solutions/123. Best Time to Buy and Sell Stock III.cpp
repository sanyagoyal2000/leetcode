class Solution {
public:
    int dp[100001][2][3];
   /* int solve(int i,vector<int>& prices,bool own,int k){
        if(i==prices.size() or k==0){
            return 0;
        }
        if(dp[i][own][k]!=-1){
            return dp[i][own][k];
        }
        else if(!own){
            int op1=solve(i+1,prices,1,k)-prices[i];
            int op2=solve(i+1,prices,0,k);
            return dp[i][own][k]=max(op1,op2);
        }
        else{
            int op1=prices[i]+solve(i+1,prices,0,k-1);
            int op2=solve(i+1,prices,1,k);
             return dp[i][own][k]=max(op1,op2);
        }
    }
    return solve(0,prices,0,k);*/
    int maxProfit(vector<int>& prices) {
        int j=2;
        //memset(dp,-1,sizeof(dp));
       int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=j;k++){
                if(i==n-1){
                    dp[i][0][k]=0;
                    dp[i][1][k]=(k>=1)?prices[i]:0;
                }
                else{
                    dp[i][0][k]=max(dp[i+1][1][k]-prices[i],dp[i+1][0][k]);
                    dp[i][1][k]=max(((k>=1)?(dp[i+1][0][k-1]+prices[i]):0),dp[i+1][1][k]);
                }
            }
        }
        return dp[0][0][j];
    }
};
