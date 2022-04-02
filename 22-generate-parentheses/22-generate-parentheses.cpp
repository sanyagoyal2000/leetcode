class Solution {
public:
    vector<string>ans;
    
    void dp(int n,int i,int o,int c,string s){
        if(i==(2*n)){
            ans.push_back(s);
        }
        if(o<n){
            dp(n,i+1,o+1,c,s+'(');
        }
        if(c<o){
            dp(n,i+1,o,c+1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        dp(n,0,0,0,"");
        return ans;
    }
};