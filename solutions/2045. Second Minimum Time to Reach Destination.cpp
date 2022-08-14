​
using PII = pair<int, int>;
class Solution {
    public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> dis(n+1, INT_MAX), dis2(n+1, INT_MAX);
        vector<vector<int>> graph(n + 1);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dis[1] = 0;
        queue<PII> Q; Q.emplace(0, 1);
        while (Q.size()) {
            auto [cost, node] = Q.front();Q.pop();
            for (auto nei: graph[node]) {
                int new_cost = cost + time;
                // red signal
                if ((cost / change) % 2 == 1){
                    new_cost += change - (cost % change);
                }
                // update two distances.
                if (dis[nei] > new_cost){
                    dis2[nei] = dis[nei]; dis[nei] = new_cost;
                    Q.emplace(new_cost, nei);
                } else if (new_cost > dis[nei] && new_cost < dis2[nei] ) {
                    dis2[nei] = new_cost;
                    Q.emplace(new_cost, nei);
                }
            }
        }
        return dis2[n];
    }
};
