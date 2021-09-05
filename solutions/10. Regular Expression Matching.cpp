class Solution {
public:
    bool isMatch(string s, string p) {
        // swap(s,p);
        int n=s.size();
        int m=p.size();
        vector<vector<bool> >dp(m+1,vector<bool>(n+1,false));
        
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 and j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=false;
                }
                else if(j==0){
                    if(p[i-1]=='*'){
                        dp[i][j]=dp[i-2][j];
                    }
                }
                else{
                    if(p[i-1]=='*'){
                        cout<<"i"<<i-1<<" ";
                        dp[i][j]=dp[i-2][j];
​
                        if(dp[i][j]==0 and( p[i-2]==s[j-1] or p[i-2]=='.') ){
                            // cout<<"i";
                            dp[i][j]=dp[i][j-1];
                        }
                    }
                    else if(p[i-1]=='.'){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[i-1]==s[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        
        
        return dp[m][n];
    }
};
