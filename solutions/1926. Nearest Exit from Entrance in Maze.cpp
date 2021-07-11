class Solution {
public:
    
    vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int nearestExit(vector<vector<char>>& a, vector<int>& v) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{v[0],v[1]},0});
​
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int ans = q.front().second;
            q.pop();
            for(auto it:dir)
            {
                int newi = i+it.first;                
                int newj = j+it.second;
                if(valid(newi,newj,n,m))
                {
                    if(a[newi][newj]=='.'&&visited[newi][newj]==false)
                    {
                        q.push({{newi,newj},ans+1});
                        visited[newi][newj] = true;
                        if((newi==0||newj==0||newi==n-1||newj==m-1)&&(newi!=v[0] || newj!=v[1]))
                        {
                            return (ans+1);
                            break;
                        }
                    }
                }
            }
        }
