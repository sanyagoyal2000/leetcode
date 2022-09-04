class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxi = 0; //to store the square side
        vector<vector<int>> dp(m, vector<int>(n)); //The 2D DP matrix
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 || j == n-1 || matrix[i][j]=='0') dp[i][j] = matrix[i][j]-'0';
                else dp[i][j] = 1 + min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
                maxi = max(maxi, dp[i][j]); //The side of the maximal square
            }
        }
        return maxi*maxi; //Area of the sqaure
    }
};