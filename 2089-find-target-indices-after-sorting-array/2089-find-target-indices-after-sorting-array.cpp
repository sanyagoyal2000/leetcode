class Solution {
public:
   vector<int> targetIndices(vector<int>& nums, int target) {
        int small=0,count=0,k=0;
        for(auto n:nums) {
            if(n<target)    small++;                                        // calculates the frequency of elements lesser than the target
            if(n==target)   count++;                                        // calculate the number of occurences of the target element
        }
        vector<int> result(count);
        for(int i=small;i<small+count;i++)      
            result[k++]=i;
        return result;
    }
};