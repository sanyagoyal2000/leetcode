class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int>visited;
        for(int i=0;i<restricted.size();i++){
            visited.insert(restricted[i]);
        }
        queue<int>q;
        int cnt=0;
        q.push(0);
        visited.insert(0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        while(!q.empty()){
            int x=q.front();
            cout<<x<<endl;
            cnt++;
            q.pop();
            for(auto nbr:adj[x]){
                if(visited.find(nbr)==visited.end()){
                    q.push(nbr);
                    visited.insert(nbr);
                    
                }
            }
        }
        return cnt;
    }
};