class Solution {
public:
   struct Trie {
    Trie* ch[2] = {};
    int cnt = 0;
    void increment(int val, int d, int pos = 17) {
        cnt += d;
        if (pos >= 0) {
            bool b = val & (1 << pos);
            if (ch[b] == nullptr)
                ch[b] = new Trie();
            ch[b]->increment(val, d, pos - 1);
        }
    }
    int match(int val, int pos = 17) {
        if (pos < 0)
            return 0;
        bool b = val & (1 << pos);
        if (ch[!b] != nullptr && ch[!b]->cnt > 0)
            return (1 << pos) + ch[!b]->match(val, pos - 1);
        return ch[b] == nullptr ? 0 : ch[b]->match(val, pos - 1);
    }
};
Trie t;
void dfs(unordered_map<int, vector<pair<int, int>>> &q, vector<vector<int>> &al, vector<int> &res, int ni) {
    t.increment(ni, 1);
    for (auto [i, val] : q[ni])
        res[i] = t.match(val);
    for (auto nj : al[ni])
        dfs(q, al, res, nj);
    t.increment(ni, -1);
}
vector<int> maxGeneticDifference(vector<int>& pars, vector<vector<int>>& qs) {
    vector<vector<int>> al(pars.size());
    vector<int> res(qs.size());
    int root = -1;
    unordered_map<int, vector<pair<int, int>>> q;
