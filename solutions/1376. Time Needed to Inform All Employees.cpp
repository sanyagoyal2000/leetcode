class Solution {
public:
    int util(vector<int>& manager, vector<int>& informTime, int s, vector<int> &dp){
        if(manager[s]==-1){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s];
        }
        dp[s]=informTime[manager[s]]+util(manager, informTime, manager[s], dp);
        return dp[s];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> dp(n,-1);
        int i;
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                dp[i]=util(manager, informTime, i, dp);
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
