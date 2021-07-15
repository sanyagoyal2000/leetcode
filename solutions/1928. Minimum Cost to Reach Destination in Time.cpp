​
​
​
#define pr pair<int, pair<int, int>>
#define ll long long int
​
class Solution {
public:
​
    
    int minCost(int maxTime, vector<vector<int>>& ed, vector<int>& pass) {
        int n = pass.size();
        vector<pair<int, int>> adj[n];
        
        //making a graph
        for(vector<int> e: ed) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        //taking min priority queue as {cost, vertex, time} 
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        //Initial vertex
        pq.push({pass[0], {0, 0}});
        
        //map to track of vertex which is visited with minimum time
        //It maps vertex and minimum time to reach that vertex
        unordered_map<int, int> vis;
        
        
        //Simple Dijstra algorithm
        while(!pq.empty()) {
            pr crr = pq.top(); pq.pop();
            int curr = crr.second.first, time = crr.second.second, cost = crr.first;
            
            //Destination
            if(curr == n-1) return cost;
            
            //Visited with current time
            vis[curr] = time;
            
            for(pair<int, int> p: adj[curr]) {
                int ad = p.first, ctime = p.second;
                int ttime = time + ctime;
                
                //if vertex is not visited or vertex is visited prior but with more time, we push it into queue else continue
                if(vis.find(ad) != vis.end() && vis[ad] <= ttime) continue;
                vis[ad] = ttime;
                //check if total time is less or equal to maxTime
                if(ttime <= maxTime) pq.push({cost + pass[ad], {ad, ttime}});
            }
            
        }
        
        //Not possible
        return -1;
        
        //If you understood please upvote!!!
    }
};
