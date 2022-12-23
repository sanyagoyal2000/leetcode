​
class Solution {
    int solve(vector<vector<int>>&obstacleGrid, int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || i>=m || j <0 || j>=n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == m-1 && j == n-1) {
            dp[i][j] = 1;
        } 
        else {
            dp[i][j] = solve(obstacleGrid, m, n, i+1, j, dp) + solve(obstacleGrid, m, n, i, j+1, dp);
        }
        return dp[i][j];
    }
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(obstacleGrid, m, n, 0, 0, dp);
        
    }
};
