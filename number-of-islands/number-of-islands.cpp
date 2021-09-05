int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
class Solution {
public:
    bool isSafe(int x,int y,int r,int c){
        if(x>=0 and x<r and y>=0 and y<c)return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int r,int c){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(isSafe(nx,ny,r,c) and !visited[nx][ny] and grid[i][j]=='1'){
                dfs(grid,visited,nx,ny,r,c);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int cnt=0;
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] and grid[i][j]=='1'){
                    dfs(grid,visited,i,j,r,c);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};