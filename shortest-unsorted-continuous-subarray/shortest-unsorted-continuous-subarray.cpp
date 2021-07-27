class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>a=nums;
        sort(a.begin(),a.end());
        int n=nums.size();
        int c=0;
        int i,j;
        for(i=0;i<n;i++){
            if(nums[i]!=a[i]){
                break;
            }
        }
        for(j=n-1;j>i;j--){
            if(a[j]!=nums[j]){
                break;
            }
        }
        if(i==n)return 0;
        if(i==j)return 1;
        else return j-i+1;
        return c;
    }
};