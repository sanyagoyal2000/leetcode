class Solution {
public:
    bool isSafe(int x,vector<string>&ans,int y,int n){
        //same col
        for(int i=0;i<x;i++){
            if(ans[i][y]=='Q')return false;
        }
        //left diagonal
        int i=x;
        int j=y;
        while(i>=0 and j>=0){
            if(ans[i][j]=='Q')return false;
            i--;
            j--;
        }
        //right diagonal
        i=x;
        j=y;
        while(i>=0 and j<n){
            if(ans[i][j]=='Q')return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(vector<string>ans,int i,int n,vector<vector<string> >&res){
        if(i==n){
            res.push_back(ans);
            return;
        }
        for(int j=0;j<n;j++){
            
            if(isSafe(i,ans,j,n)){
                ans[i][j]='Q';
               helper(ans,i+1,n,res);
                ans[i][j]='.';
            }
            
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
      if(n <= 0) return {{}};
​
        vector<vector<string>>res;
        vector<string> ans(n,string(n,'.'));        
        helper(ans,0,n,res);
        return res;
    }
};
