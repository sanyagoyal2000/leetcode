#define pb push_back
class Solution {
    string arr[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void solve(string digits,vector<string>&res,int i,string a){
        if(i==digits.size()){
            res.pb(a);
            return;
            }
        int curr=digits[i]-'0';
        for(int k=0;k<arr[curr].size();k++){
            solve(digits,res,i+1,a+arr[curr][k]);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size()==0)return res;
        string a="";
        solve(digits,res,0,a);
        return res;
    }
};