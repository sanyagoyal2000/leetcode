class Solution {
public:
    int LPS(string s){
        int n = s.size();
        vector<int>lps(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                   len=lps[len-1]; 
                }
                else{
                    lps[i]=0;
                    i++;
                }
                
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        t=s+'#'+t;
        int n = s.size();
        
        int len = LPS(t);
        string ans = "";
        for(int j = n-1; j >= len; j--){
            ans += s[j];
        }
        ans += s;
        return ans;
    
    }
};