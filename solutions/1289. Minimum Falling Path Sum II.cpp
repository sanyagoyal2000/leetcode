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
​
/*
bottom-up
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // find the minimum from the prev row
                
                int mini = INT_MAX;
                
                for(int k = 0; k < m; k++)
                {
                    if(k != j)
                    {
                        mini = min(mini, grid[i - 1][k]);
                    }
                }
                
                // update grid[i][j]
                
                grid[i][j] += mini;
            }
        }
        
        return *min_element(grid[n - 1].begin(), grid[n - 1].end());
    }
};
*/
