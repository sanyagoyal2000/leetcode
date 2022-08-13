class Solution {
public:
    int maxi(int a,int b,int c,int d){
        return max(max(a,b),max(c,d));
    }
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j,int m,int n,int par){
        if(i<0 or j<0 or i>=m or j>=n or par>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= 1+maxi(dfs(matrix,dp,i+1,j,m,n,matrix[i][j]), dfs(matrix,dp,i,j+1,m,n,matrix[i][j]), dfs(matrix,dp,i-1,j,m,n,matrix[i][j]), dfs(matrix,dp,i,j-1,m,n,matrix[i][j]));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(matrix,dp,i,j,m,n,-1));
            }
        }
        return ans;
    }
};
