class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+'#'+rev;
        //kmp  lps
        int n=temp.length();
        vector<int> lps(n,0);
        int len = 0, i = 1;
        while(i < n) {
            if(temp[len] == temp[i]) {
                len++;
                lps[i] =len;
                i++;
            } 
            else {
                if(len != 0){
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        temp=s.substr(lps[n-1]);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};