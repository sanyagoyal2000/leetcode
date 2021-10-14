class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int me=nums[0],ms=nums[0];
        int n=nums.size();
        if(n>1){
        for(int i=1;i<nums.size();i++){
            me=me+nums[i];
            me=max(me,nums[i]);
            ms=max(ms,me);
        }}
        return ms;
    }
};