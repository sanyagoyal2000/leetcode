#define pb push_back
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int> >m;
vector<int>ans;
for(int i=0;i<nums.size();i++)
{
for(int j=0;j<nums[i].size();j++)
{
m[i+j].push_back(nums[i][j]);
}
​
    }
   
    for(auto x:m)
    {
        while(x.second.size()>0)
            
        {
            
            ans.push_back(x.second.back());
            x.second.pop_back();
        }
        
    }
    return ans;
    }
};
