class Solution {
public:
    vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string>res;
    void dp(int i,int n,string s,string &digits){
        if(i==n){
            res.push_back(s);
            return;
        }
        int curr=digits[i]-'0';
        if(curr==0 or curr==1){
            dp(i+1,n,s,digits);
        }
        for(int k=0;k<v[curr].size();k++){
            dp(i+1,n,s+v[curr][k],digits);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0)return res;
        dp(0,n,"",digits);
        return res;
    }
};