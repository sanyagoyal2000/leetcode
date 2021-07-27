class Solution {
public:
    int search(vector<int>& nums, int target, int left, int right){
        if(left>right)
            return -1;
        
        int mid = (left + right)/2;
        
        if(nums[mid]==target)
            return mid;
        
        if(nums[left] <= nums[mid]){
            if(nums[left]<=target && nums[mid]>=target)
                return search(nums, target, left, mid-1);
            
            else
                return search(nums, target, mid+1, right);
        }    
        
        if(nums[mid]<=target && nums[right]>=target)
            return search(nums, target, mid+1, right);
        
        else
            return search(nums, target, left, mid-1);
        
    }
    
    int search(vector<int>& nums, int target) {
        
        int index = search(nums, target, 0, nums.size()-1);
        
        return index;
        
    }
};
