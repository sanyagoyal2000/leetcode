//https://leetcode.com/problems/the-time-when-the-network-becomes-idle/discuss/2549706/very-intuitive-and-basic-oror-explained

class Solution {
public:
void bfs(vector<int> adj[],int n,vector<int>& dist){
    vector<bool> vis(n,false);
   vis[0]=true;
   queue<int> q;
   q.push(0);
   int level=1;
   while(!q.empty()){
    int n=q.size();
     for(int i=0;i<n;i++){
     int a=q.front();
     q.pop();
     for(int j=0;j<adj[a].size();j++){
       if(!vis[adj[a][j]]){
        vis[adj[a][j]]=true;
        dist[adj[a][j]]=level;
      q.push(adj[a][j]);
        }
      }
    }
   level++;
  }
}
    
int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
    int n=pat.size();
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> dist(n,0);
    bfs(adj,n,dist);
    int ans=INT_MIN;
    for(int i=1;i<n;i++){
        int pos=(2*dist[i]-1)/pat[i];
        int val=pos*(pat[i]);
        int final_val=val+2*dist[i];
        ans=max(ans,final_val);
    }
    return ans+1;
}
};