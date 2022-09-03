class Solution {
public:
    bool solve(string A,unordered_set<string>&B,int i,vector<int>&dp){
    if(i >= A.size()){
        return true;
    }
    
    if(dp[i]!=-1){
        return dp[i];
    }
    string curr = "";
    for(int j=i;j<A.size();j++){
        curr+=A[j];  
        if(B.find(curr)!=B.end()){                     // if present then call further
            if(solve(A,B,j+1,dp)){
                return dp[i] =  true;
            }
        }
    }
    return dp[i] = false;
}
bool wordBreak(string A, vector<string>& B) {
    vector<int>dp(A.size(),-1);
    unordered_set<string>dic;
    for(int i=0;i<B.size();i++){
        dic.insert(B[i]);
    }
    return solve(A,dic,0,dp);
}
};