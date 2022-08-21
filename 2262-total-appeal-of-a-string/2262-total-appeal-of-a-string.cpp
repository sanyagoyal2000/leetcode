class Solution {
public:
    long long appealSum(string s) {
    long long res = 0, n = s.size(), prev[26] = {};
    for (int i = 0; i < n; ++i) {
        res += (i + 1 - prev[s[i] - 'a']) * (n - i);
        prev[s[i] - 'a'] = i + 1;
    }
    return res;
}
};