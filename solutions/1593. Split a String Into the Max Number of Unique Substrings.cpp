class Solution {
public:
    int maxUniqueSplit(string s) 
    {
        unordered_set<string> mp;
        int ret = 0;
        helper(s, mp, 0, ret);
        return ret;
    }
    void helper(string s, unordered_set<string>& mp, int cnt, int& ret)
    {
        if(s == "")
        {
            ret = max(ret, cnt);
            return;
        }
        for(int i = 1; i <= s.size(); i++)
        {
            if(!mp.count(s.substr(0, i)))
            {
                mp.insert(s.substr(0, i));
                helper(s.substr(i), mp, cnt+1, ret);
                mp.erase(mp.find(s.substr(0, i)));
            }
        }
        return;
    }
};
