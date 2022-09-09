class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& as) {
        int n = source.size(), size = as.size();
        vector<bool> visited(n);
        vector<vector<int>> edges(n);
        for(vector<int>& v : as){
            edges[v[0]].push_back(v[1]);
            edges[v[1]].push_back(v[0]);
        }
        
        function<void(int, vector<int>&, map<int, int>&)> dfs = [&](int now, vector<int>& s, map<int, int>& t) {
            visited[now] = 1;
            s.push_back(source[now]);
            t[target[now]]++;
            for(int edge : edges[now]) {
                if(!visited[edge])
                    dfs(edge, s, t);
            }
        };
        
        int cnt = n;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> s;
                map<int, int> t;
                dfs(i, s, t);
                for(int j = 0; j < s.size(); j++)
                    if(t.find(s[j]) != t.end() && t[s[j]] > 0)
                        t[s[j]]--, cnt--;
            }
        }
        return cnt;
    }
};