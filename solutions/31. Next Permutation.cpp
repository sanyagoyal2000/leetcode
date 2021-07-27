class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n = nums.size();
        if(n==1)
            return;
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                break;
            }
        }
        sort(nums.begin()+i,nums.end());
        if(i>=1)
        {
            int index = upper_bound(nums.begin()+i,nums.end(),nums[i-1]) - nums.begin();
            swap(nums[i-1],nums[index]);
        }
    }
};
