class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)dp[i][j]=nums[i];
                else if(g==1)dp[i][j]=max(nums[i],nums[j]);
                else{
                    int val1=nums[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2=nums[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j]=max(val1,val2);
                }
            }
        }
        int p=dp[0][n-1];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(n==1)return true;
        
        if(p>=(sum-p))return true;
        return false;
    }
};
​
/*
class Solution {
public:
    int dfs(vector<int>& nums,int s,int e){
        if(s==e or s==(e-1)){
            return max(nums[s],nums[e]);
        }
        int op1=nums[s]+min(dfs(nums,s+2,e),dfs(nums,s+1,e-1));
        int op2=nums[e]+min(dfs(nums,s+1,e-1),dfs(nums,s,e-2));
        return max(op1,op2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n=nums.size();
        if(n==1)return true;
        int pl1=dfs(nums,0,n-1);
        if(pl1>=(sum-pl1))return true;
        return false;
    }
};
*/
