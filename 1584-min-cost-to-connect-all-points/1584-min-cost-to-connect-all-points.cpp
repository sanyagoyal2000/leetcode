vector<pair<int,int>>adj[1001];
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //find the ans wer calle dof rhte m
        //rate is called of het maindfsdfsdfdsfdshiouhoiudf sadfsd
        //is solve teh create is calle fd
        int n=points.size();
        for(int i=0;i<=n;i++){
            adj[i].clear();
        }
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
               int y2=points[j][1];
                int val=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,val});
                adj[j].push_back({i,val});
            }
        }
        vector<int>visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node]=1;
            ans+=w;
            for(auto x:adj[node]){
                if(visited[x.first]==0){
                    pq.push({x.second,x.first});
                }
            }
            
        }
        return ans;
    }
};