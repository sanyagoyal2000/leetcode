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
