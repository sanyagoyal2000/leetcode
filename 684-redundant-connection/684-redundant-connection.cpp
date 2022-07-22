class Solution {
public:

    bool dfs(vector<vector<int>> &graph,vector<bool> &vis,int node,int par = -1){
        if(vis[node]==true)return true;
        vis[node]=true;
        for(auto nbr:graph[node]){
            if(!vis[nbr]){
                    bool nbrFound=dfs(graph,vis,nbr,node);
                    if(nbrFound)return true;
               }
               //nbr is visited and it is not the parent of current node in dfs call
               else if(nbr!=par)return true;
          }
          return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        	vector<bool> vis(n+1,false);                

        for(auto &e :edges){
            
            fill(begin(vis), end(vis), false);     // reset the vis array
        graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);
            if(dfs(graph,vis,e[0]))return e;
        }
        return {};
    }
};