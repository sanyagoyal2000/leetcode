class Solution {
public:
    int dp[50][50][50];
    int fn(vector<vector<int>>& grid,int n,int r1,int c1,int c2){
        int r2=(r1+c1)-c2;
		
		//neglected base cases
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1 )
            return INT_MIN;
        
		//reached destination
        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];
        
        int ans=grid[r1][c1];
		
		//make sure both are not on the same index
        if(c1!=c2)
            ans+=grid[r2][c2];
        
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        
		//going all possibilities
        int op1=fn(grid,n,r1+1,c1,c2);
        int op2=fn(grid,n,r1,c1+1,c2+1);
        int op3=fn(grid,n,r1,c1+1,c2);
        int op4=fn(grid,n,r1+1,c1,c2+1);
        
        ans+=max({op1,op2,op3,op4});
        
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,fn(grid,n,0,0,0));
    }
};