class Solution {
public:
    bool helper(vector<int>&nums,vector<bool>&visited,int req,int curr,int i,int k){
        if(k==0)return true;
        if(curr==req){
            return helper(nums,visited,req,0,0,k-1);
        }
        for(int j=i;j<nums.size();j++){
            if(!visited[j] and nums[j]+curr<=req){
                visited[j]=true;
                bool temp=helper(nums,visited,req,curr+nums[j],i+1,k);
                if(temp)return true;
                visited[j]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n=nums.size();
        
        if(sum%k!=0 or n<k )return false;
        vector<bool>visited(nums.size(), false);
        return helper(nums, visited, sum / k, 0, 0, k);
    }
};