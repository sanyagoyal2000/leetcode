class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxe=nums[0];
        int mine=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxe,mine);
            }
            maxe=max(nums[i],(maxe*nums[i]));
            mine=min(nums[i],(mine*nums[i]));
            ans=max(ans,maxe);
        }
        return ans;
    }
};