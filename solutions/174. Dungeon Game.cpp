class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,INT_MAX));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                int health=min(right,down);
                if(health==INT_MAX){
                    health=1;
                }
                int res=0;
                if(health-dungeon[i][j]>0){
                    res=health-dungeon[i][j];
                }
                else{
                    res=1;
                }
                dp[i][j]=res;
            }
        }
        return dp[0][0];
    }
};
