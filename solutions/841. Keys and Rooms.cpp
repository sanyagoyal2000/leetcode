class Solution {
public:
void dfs(int node ,vector<vector<int>>& rooms,vector<int> &visited){
    visited[node]=1;
    for(auto x: rooms[node]){
        if(!visited[x]){
            dfs(x,rooms,visited);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<int> visited(n,0);
        int start=0;
        dfs(start,rooms,visited);
     for (auto k : visited) if(k==0) return false;
     return true;
        
​
       }
};
