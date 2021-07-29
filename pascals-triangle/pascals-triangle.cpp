class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //ith row has i+1 col
        vector<vector<int>>dp(numRows,vector<int>(numRows,0));
        dp[0][0]=1;
        dp[0].resize(1);
        
       for(int i=1;i<numRows;i++){
           for(int j=0;j<=i;j++){
               if(j==0)dp[i][j]=1;
               else if(j==i)dp[i][j]=1;
                else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }   
           }
           dp[i].resize(i+1);
       }
        return dp;
    }
};