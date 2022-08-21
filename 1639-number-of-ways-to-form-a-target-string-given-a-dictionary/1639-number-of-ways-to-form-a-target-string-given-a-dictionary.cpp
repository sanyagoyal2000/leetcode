class Solution {
public:
    //https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/discuss/2413915/C%2B%2B-solution-DP-%2B-preprocessing
    //
    //https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/discuss/1986176/Python3-DP-solution-with-image-explanation-(beats-99)
       int numWays(vector<string>& words, string target) {
        int n = target.length(), mod = 1e9 + 7;
        vector<long> res(n + 1);
        res[0] = 1;
        for (int i = 0; i < words[0].length(); ++i) {
            vector<int> count(26);
            for (auto& w : words)
                count[w[i] - 'a']++;
            for (int j = n - 1; j >= 0; --j) {
                res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
            }
        }
        return res[n] % mod;
    }
};