class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int mae=0;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    mae=max(mae,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return mae;
    }
};