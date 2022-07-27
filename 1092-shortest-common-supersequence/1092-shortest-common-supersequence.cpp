class Solution {
public:
    string lcs(string &a,string &b){
        int m=a.size();
        int n=b.size();
        vector<vector<string>>dp(m+1,vector<string>(n+1,""));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+a[i];
                else dp[i+1][j+1]=(dp[i+1][j].size()>dp[i][j+1].size())?dp[i+1][j]:dp[i][j+1];
            }
        }
        return dp[m][n];
    }
     
    string shortestCommonSupersequence(string A, string B) {
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs(A, B)) {
            while (A[i] != c)
                res += A[i++];
            while (B[j] != c)
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }
    
};