class Solution {
public:
int solve(vector<vector<int>>& mat,int r,int c,vector<vector<int>>&dp)
    {
        if(c<0||c>=mat.size())return 1000000;
        if(r==mat.size()-1)return mat[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int k1=1000000,k2=1000000,k3=1000000;
         k1=mat[r][c]+solve(mat,r+1,c-1,dp);
         k2=mat[r][c]+solve(mat,r+1,c,dp);
         k3=mat[r][c]+solve(mat,r+1,c+1,dp);
        return dp[r][c]=min({k1,k2,k3});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),k=1000000;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<mat.size();i++)
            k=min(k,solve(mat,0,i,dp));
        return k;
    }
};