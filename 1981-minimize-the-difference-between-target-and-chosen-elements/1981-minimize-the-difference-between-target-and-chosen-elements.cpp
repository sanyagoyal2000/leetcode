class Solution {
public:
    int dp[5000][71];
    int rows,cols;
    int helper(vector<vector<int>>& mat,int& target,int r,int sum){
        if(r == rows){
            return abs(sum - target);
        }
        
        if(dp[sum][r] != -1){
            return dp[sum][r];
        }
        int minDiff = INT_MAX;
        for(int j = 0;j<cols;j++){
            minDiff = min(minDiff,helper(mat,target,r+1,sum+mat[r][j]));
        }
        
        return dp[sum][r] = minDiff;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        rows =  mat.size();
        cols = mat[0].size();
        memset(dp,-1,sizeof dp);
        // vector<vector<int>> dp(9000,vector<int>(rows,-1));
        
        return helper(mat,target,0,0);
    }
};