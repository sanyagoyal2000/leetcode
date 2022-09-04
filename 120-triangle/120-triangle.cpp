class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       vector<vector<int>>dp(triangle);
       int m=triangle.size();
       for(int i=m-2;i>=0;i--){
           for(int j=i;j>=0;j--){
               dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
           }
       }
        return dp[0][0];
    }
};