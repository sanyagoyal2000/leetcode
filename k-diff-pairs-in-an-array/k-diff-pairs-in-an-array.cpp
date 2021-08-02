class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        // edge case k == 0, we hunt for duplicates
        if (!k) {
            unordered_map<int, int> frequencies;
            for (int n: nums) frequencies[n]++;
            for (auto e: frequencies) if (e.second > 1) res++;
        }
        // all the other cases
        else {
            unordered_set<int> seen(begin(nums), end(nums));
            for (int n: seen) {
                res += seen.find(k + n) != end(seen);
            }
        }
        return res;
    }
};