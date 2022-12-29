class Solution {
public:
    void dfs(vector<int>adj[],vector<bool>&vis,int src){
        vis[src]=true;
        for(auto nbr:adj[src]){
            if(!vis[nbr]){
                dfs(adj,vis,nbr);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};