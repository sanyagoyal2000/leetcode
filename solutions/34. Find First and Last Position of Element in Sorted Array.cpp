class Solution {
public:
    int bs(vector<int>&nums,int k,bool flag){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==k){
                ans=mid;
                (flag==true)?r=mid-1:l=mid+1;
            }
            else if(nums[mid]>k)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        
        if(nums.size()==0 or nums[nums.size()-1]<target)return ans;
        
        ans[0]=(bs(nums,target,true));
        ans[1]=(bs(nums,target,false));
        return ans;
​
    }
};
​
