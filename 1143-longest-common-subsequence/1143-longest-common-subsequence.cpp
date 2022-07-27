class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0)dp[i][j]=0;
                else{
                dp[i][j] = (text1[i-1]==text2[j-1]) ? (dp[i-1][j-1]+1) :(max(dp[i-1][j],dp[i][j-1]));
            }}
        }
        return dp[m][n];*/
        //space optimized
           int n=text1.size();
           int m=text2.size();

         vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev= cur;
    }
    
    return prev[m];
}
    
};