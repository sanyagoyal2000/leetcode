class Solution {
public:
    int LPS(string s){
        int n = s.size();
        vector<int>lps(n,0);
        int len = 0;
        int i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len > 0){
                    len = lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        string t = s + "#";
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            t += s[i];
        }
        int len = LPS(t);
        string ans = "";
        for(int j = n-1; j >= len; j--){
            ans += s[j];
        }
        ans += s;
        return ans;
    }
};