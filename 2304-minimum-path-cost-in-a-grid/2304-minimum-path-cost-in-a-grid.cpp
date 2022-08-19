class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        vector<vector<int>>dp(grid);
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<c;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
              int prevCost=INT_MAX;
                for(int k=0;k<c;k++){
                    prevCost=min(prevCost,dp[i-1][k]+cost[grid[i-1][k]][j]);
                }
                dp[i][j]=prevCost+grid[i][j];
            }
        }
        int res=INT_MAX;
        for(int i=0;i<c;i++){
            res=min(res,dp[r-1][i]);
        }
        return res;
    }
};