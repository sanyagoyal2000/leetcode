class Solution {
public:
    /*
    we can either replace insert delete
     replace. insert
     delete   your key
     if the characters are equal you need to look for the strings before that character so dp[i-1][j-1]
     else the operation through which the ans is min
     0 r o s
     h
     o
     r
     s
     e
    */
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int i=1;i<=n;i++){
            dp[0][i]=dp[0][i-1]+1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m][n];
    }
};