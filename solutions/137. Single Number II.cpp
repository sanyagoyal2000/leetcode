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
​
/*
// hard to think // Time Complexity - O(N) // Space Complexity - O(1)
    int singleNumber(vector<int>& nums) {
        int ones = 0; // store only element whos frequency is one
        int twos = 0; // store only element whos frequency is two
        for (auto x : nums) {
            ones = (ones ^ x) & (~twos);
            twos = (twos ^ x) & (~ones);
        }
        return ones;
    }
};
*/
