#define pb push_back

class Solution {
public:
    void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<vector<int>>& bridge,vector<int>adj[])
{
	static int time = 0;
	disc[u] = low[u] = time;
	time+=1;

	for(int v: adj[u])
	{
		if(disc[v]==-1)	//If v is not visited
		{
			parent[v] = u;
			DFS(v,disc,low,parent,bridge,adj);
			low[u] = min(low[u],low[v]);

			if(low[v] > disc[u])
				bridge.pb({u,v});
		}
		else if(v!=parent[u])	//Ignore child to parent edge
			low[u] = min(low[u],disc[v]);
	}
}
      

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> disc(n,-1),low(n,-1),parent(n,-1);
	vector<vector<int>> bridge;

	for(int i=0;i<n;++i)
		if(disc[i]==-1)
			DFS(i,disc,low,parent,bridge,adj);

	return bridge;
    }
};