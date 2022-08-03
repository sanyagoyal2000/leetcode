class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxi=INT_MIN,maxe=0;
        for(int i=0;i<nums.size();i++){
            maxe+=nums[i];
            maxe=max(nums[i],maxe);
            maxi=max(maxi,maxe);
        }
        return maxi;
    }
    
};