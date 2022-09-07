class Solution {
    void solve(vector<int> &nums,int idx,int n,int acc,int sum,vector<vector<int>> &v)
    {
        if(idx == n)
        {
           v[acc].push_back(sum);
        }
        else
        {
            solve(nums,idx+1,n,acc,sum-nums[idx],v);
            solve(nums,idx+1,n,acc+1,sum+nums[idx],v);
        }
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<vector<int>> va(n+1),vb(n+1);
        solve(nums,0,n,0,0,va);
        solve(nums,n,2*n,0,0,vb);
        for(int i=0;i<=n;i++)
        {
            sort(va[i].begin(),va[i].end());
            sort(vb[i].begin(),vb[i].end());
        }
        int ans = 1e9;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<va[i].size();j++)
            {
                int tar = -va[i][j];
                if(tar <= vb[n-i][0])
                {
                    ans = min(ans,abs(va[i][j] + vb[n-i][0]));
                }
                else if(tar >= vb[n-i].back())
                {
                    ans = min(ans,abs(va[i][j] + vb[n-i].back()));
                }
                else
                {
                    int idx = lower_bound(vb[n-i].begin(),vb[n-i].end(),tar) - vb[n-i].begin();
                    int val = min(abs(va[i][j] + vb[n-i][idx]),abs(va[i][j] + vb[n-i][idx-1]));
                    ans = min(ans,val);
                }
            }
        }
        return ans;
    }
};