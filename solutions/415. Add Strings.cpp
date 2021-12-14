class Solution {
public:
    string addStrings(string num1, string num2) {
        int m=num1.size()-1;
        int n=num2.size()-1;
        int c=0;
        string ans="";
        while(n>=0 or m>=0 or c){
            int sum=0;
            if(m>=0){
                sum+=num1[m]-'0';
                m--;
            }
            if(n>=0){
                sum+=num2[n]-'0';
                n--;
            }
            sum+=c;
            c=sum/10;
            ans+=sum%10 +'0';
        }
        
       reverse(ans.begin(), ans.end());
        return ans;
    }
};
