class Solution {
public:
    int lower(vector<int>&nums,int k){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==k){
                ans=mid;
                r=mid-1;
            }
            else if(nums[mid]>k)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    int upper(vector<int>&nums,int k){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;

            if(nums[mid]==k){
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>k)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        
        if(nums.size()==0 or nums[nums.size()-1]<target)return ans;
        
        ans[0]=(lower(nums,target));
        ans[1]=(upper(nums,target));
        return ans;

    }
};
