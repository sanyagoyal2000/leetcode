class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0,start=0;
     bool dp[n][n];
     
          int g=0;
          for(;g<n;g++){
               for(int i=0,j=g;j<n;i++,j++){
                    if(g==0){
                         dp[i][j]=true;
                    }
                    else if(g==1){
                         dp[i][j]=(s[i]==s[j])?true:false;
                    }
                    else{
                         if(s[i]==s[j] and dp[i+1][j-1]==true){
                              dp[i][j]=true;
                         }
                         else{dp[i][j]=false;}
                    }
                 if(dp[i][j]){
                      
                      len=g+1;
                      start=i;
                 }
               }
              
               
          }
        return s.substr(start,len);
     
  
}
};