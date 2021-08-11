class Solution {
public:
    int dp[100001][2][3];
    int solve(int i,vector<int>& prices,bool own,int k){
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
    int maxProfit(vector<int>& prices) {
        int k=2;
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,0,k);
    }
};
