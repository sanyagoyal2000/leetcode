class Solution {
public:
    int lowerBound(vector<int>&arr,int target){
        int l=0;
        int r=arr.size()-1;
        int ans=arr.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>=target){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
      int upperBound(vector<int>&arr,int target){
        int l=0;
        int r=arr.size()-1;
        int ans=arr.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>target){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lowerBound(nums,target);
        int u=upperBound(nums,target);
        if(l==(nums.size()) or nums[l]!=target)return {-1,-1};
        
        return {l,(u-1)};
    }
};