//https://leetcode.com/problems/longest-duplicate-substring/discuss/1548431/Learning-notes-on-Rabin-Karp-algorithm
class Solution {
    static constexpr int kMod = 1e7 + 7;
    int size;
    vector<int> power;
public:
    string rabin_karp(const string &s, int length){
        if (length == 0)    return "";
        int current = 0;
        unordered_map<int, vector<int>> hash_table;
        for (int i = 0; i < length; ++i)
            current = (current * 26 + (s[i] - 'a')) % kMod;
        hash_table[current] = {0};
        for (int i = length; i < size; ++i){
            // update current hash
            current = ((current - power[length - 1] * (s[i - length] - 'a')) % kMod + kMod) % kMod;
            current = (current * 26 + (s[i] - 'a')) % kMod;
            if (hash_table.count(current) == 0){
                hash_table[current] = {i - length + 1};
            }else{
                // double check to avoid collision
                for (int index : hash_table[current]){
                    if (s.substr(index, length) == s.substr(i - length + 1, length))
                        return s.substr(index, length);
                }
                hash_table[current].push_back(i - length + 1);
            }
        }
        return "";
    }
    
    
    string longestDupSubstring(string s) {
