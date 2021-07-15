class Solution {
public:
    int n;
	//  {key = city u, value = {key = city v, value = time required to travel from city u to v} }
    vector<unordered_map<int, int>> graph;
    vector<vector<int>>dp;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        n = fee.size();
        dp = vector<vector<int>>(n, vector<int>(maxTime+1, -1));
        graph = vector<unordered_map<int, int>>(n);
        // build the graph, keep weights which are minimum if multiple paths are present between same pair of nodes
        for(auto &e : edges){
            if(graph[e[0]].count(e[1]) == 0) graph[e[0]][e[1]] = e[2];
            else graph[e[0]][e[1]] = min(graph[e[0]][e[1]], e[2]);
            if(graph[e[1]].count(e[0]) == 0) graph[e[1]][e[0]] = e[2];
            else graph[e[1]][e[0]] = min(graph[e[1]][e[0]], e[2]);
        }
        int ans = dfs(fee, 0, maxTime);
        return ans == INT_MAX ? -1 : ans;
    }
    
    int dfs(vector<int>& fee, int u, int time){
        if(u == n-1) return fee[u];
        if(dp[u][time] != -1) return dp[u][time];
        
        int ans = INT_MAX;
        for(auto &e : graph[u]){
            int v = e.first;
            int vtime = e.second;
            if(time - vtime >= 0){
                int val = dfs(fee, v, time-vtime);
                if(val != INT_MAX){
                    ans = min(ans, fee[u] + val);
                }
            }
        }
        return dp[u][time] = ans;
    }
};