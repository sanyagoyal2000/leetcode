class Solution {
public:
    string longestPalindrome(string s) {
   vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int len = 0,start = 0;
        for(int g=0;g<s.size();g++)
        {
            for(int i=0,j=i+g;j < dp.size();i++,j++)
            {
                if(i == j)
                    dp[i][j] = true;
                else{
                    if(s[i] == s[j])
                    {
                        if(i+1 == j)
                        {
                            dp[i][j] = true;
                        }else{
                            dp[i][j] = dp[i+1][j-1];       
                        }
                    }else{
                        continue;
                    }
                }
                if(dp[i][j])
                {
                    len =g + 1;
                    start = i;
                }
                
            }
        }
        return s.substr(start,len);
     
  
}
};