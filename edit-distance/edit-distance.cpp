class Solution {
public:
    int solve(string a,string b,int m,int n){
        if(m==0)return n;
        if(n==0)return m;
        if(a[m-1]==b[m-1])return solve(a,b,m-1,n-1);
        return (1+min(solve(a,b,m,n-1),min(solve(a,b,m-1,n),solve(a,b,m-1,n-1))));
    }
    int editDistDP(string str1, string str2, int m, int n)
{
   
    int dp[m + 1][n + 1];
  
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            
            if (i == 0)
                dp[i][j] = j; // Min. operations = j
  
            
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i
  
            
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
  
            
            else
                dp[i][j]
                    = 1
                      + min(dp[i][j - 1],min(// Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1])); // Replace
        }
    }
  
    return dp[m][n];
}
    int minDistance(string word1, string word2) {
        int n= word2.size();
        int m= word1.size();
        //int ans=solve(word1,word2,m,n);
        int ans=editDistDP(word1,word2,m,n);
        return ans;

        
    }
};