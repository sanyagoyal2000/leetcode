 int cherryPickup(vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int j=0;j<n;j++){//base case
            for(int k=0;k<n;k++){
                if(j==k)
                    dp[m-1][j][k]=grid[m-1][j];
                else
                    dp[m-1][j][k]=grid[m-1][j]+grid[m-1][k];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int maxi=-1e8;
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            int value=0;
                            if(j==k)value=grid[i][j];
                            else value=grid[i][j]+grid[i][k];
                            if(j+x>=0 && j+x <=n-1 && k+y>=0 && k+y<=n-1)
                                value+=dp[i+1][j+x][k+y];
                            else 
                                value+=-1e8;
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j][k]=maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
​
*/
