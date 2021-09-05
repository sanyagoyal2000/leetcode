int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//map<pair<int,int>,pair<int,int> >m;
class Solution {
public:
    bool isSafe(int x,int y,int r,int c,vector<vector<bool> >&visited){
        if(x>=0 and x<r and y>=0 and y<c and !visited[x][y])return true;
        return false;
    }
    pair<int,int> dfs(vector<vector<int>>& land,vector<vector<bool> >&visited,int r,int c,int row,int col){
         visited[row][col] = true;
         pair<int,int>res=make_pair(row,col);
    
    for (int k = 0; k < 4; ++k){
        
        if (isSafe(row + dx[k], col + dy[k],r,c ,visited) and land[row + dx[k]][col + dy[k]]==1){
            pair<int,int>ans=dfs(land,visited,r,c, row + dx[k], col + dy[k]);
            res.first=max(res.first,ans.first);
            res.second=max(res.second,ans.second);
        }}
        return res;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int> >res;
        int r=land.size();
        int c=land[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
 
            if (land[i][j]==1 && !visited[i][j]) {
                vector<int>ans;
                pair<int,int>x=dfs(land,visited,r,c,i,j);
                ans.push_back(i);
               ans.push_back(j);
              ans.push_back(x.first);
              ans.push_back(x.second);
               res.push_back(ans);
 }
            }}
        
       
        return res;
    }
};