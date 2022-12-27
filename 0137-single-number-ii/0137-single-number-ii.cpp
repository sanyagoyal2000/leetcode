//https://leetcode.com/problems/single-number-ii/discuss/2860941/4-Approach-oror-Bit-Manipulation-or-Map-or-Sorting-or-Out-of-the-box-oror-C%2B%2B-oror-Well-Explained
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(auto num:nums){
                if(((1<<i)&num)!=0)cnt++;
            }
            if((cnt%3)!=0){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};