class Solution { // memoization
    int helper(vector<vector<int>> &grid,int i,int j,int k,int r,int c,vector<vector<vector<int>>>&dp){
        if(j<0 || j>c-1 || k<0 || k>c-1)return -1e8;
        if(i==r-1){
            if(j==k)return grid[i][j];
            else return grid[i][j]+grid[i][k];
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        //we make sure they both take a step downward in the grid
        int ans=(j==k)?grid[i][j]:grid[i][j]+grid[i][k];
        int maxi=0;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                maxi=max(helper(grid,i+1,j+x,k+y,r,c,dp),maxi);
            }
        }
        return dp[i][j][k]=ans+maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(70,vector<vector<int>>(70,vector<int>(70,-1)));
        int r=grid.size();
        int c=grid[0].size();
        return helper(grid,0,0,c-1,r,c,dp);
    }
};