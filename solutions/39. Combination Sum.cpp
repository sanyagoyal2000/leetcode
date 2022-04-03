class Solution {
public:
    vector<vector<int>> ans;
    int len;
    void dfs ( vector<int> &candidates, int target, vector<int> &cur_path, int start )
    {
        if ( target < 0 ) return;
        if ( target == 0 )
        {
            ans.push_back(cur_path);
            return;
        }
        
        for ( ; start < len; ++start )
        {
            cur_path.push_back( candidates[start] );
            dfs ( candidates, target - candidates[start], cur_path, start );
            cur_path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>s;
        len=candidates.size();
        dfs(candidates,target,s,0);
        return ans;
    }
};
