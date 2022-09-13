class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i==n-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int tempAns=INT_MAX;
        for(int k=0;k<m;k++){
            if(k!=j)
                tempAns=min(tempAns,grid[i][j]+solve(grid,i+1,k,n,m));
        }
        
        return dp[i][j]=tempAns;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++)
            ans=min(ans,solve(grid,0,i,n,m));
        
        return ans;
    }
};