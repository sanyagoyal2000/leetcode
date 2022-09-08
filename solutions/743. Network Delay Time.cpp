#define pii pair<int, int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1); // (node, time)
        for(int i = 0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> visited(n+1,0);
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        priority_queue<pii, vector<pii>,greater<pii>> nodes;
        nodes.push({0,k});
        while(!nodes.empty()){
            int node = nodes.top().second;
            nodes.pop();
            visited[node] = 1;
            for(auto &x: adj[node]){
                if(time[node] + x.second < time[x.first] && !visited[x.first]){
                    time[x.first] = min(time[node]+x.second, time[x.first]);
                    nodes.push({time[x.first], x.first});
                }
            }
        }
        for(int i = 1; i<=n; i++){
            if(visited[i]==0){
                return -1;
            }
        }
        int timeToReach = time[1];
        for(int i = 1; i<=n; i++){
            // cout<<time[i]<<' ';
            timeToReach = max(timeToReach, time[i]);
        }
        return timeToReach;
    }
};
