class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int i,vector<int>&color){
        for(auto nbr:graph[i]){
            if(color[nbr]==-1){
                color[nbr]=1-color[i];
                if(!dfs(graph,nbr,color))return false;
            }
            else if(color[nbr]==color[i])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(!dfs(graph,i,color))return false;
            }
            
        }
        return true;
    }
};