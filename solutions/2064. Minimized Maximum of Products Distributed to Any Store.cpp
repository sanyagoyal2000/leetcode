class Solution {
public:
    int minimizedMaximum(int n, vector<int>& qs) {
    int l = 1, r = 100000;
    while (l < r) {
        int m = (l + r) / 2, nn = n;
        for (int i = 0; i < qs.size() && n >= 0; ++i)
            nn -= qs[i] / m + (qs[i] % m ? 1 : 0);
        if (nn >= 0)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
};
