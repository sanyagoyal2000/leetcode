class Solution {
public:
     /*void preprocessing(vector<int>adj[],int src,int par,vector<int>&subTreeSize,vector<int>&subTreeAns){
        int noNodes=1;
         int ansNodes=0;
        for(auto child:adj[src]){
            if(child!=par){
                preprocessing(adj,child,src,subTreeSize,subTreeAns);
                noNodes+=subTreeSize[child];
                ansNodes+=subTreeAns[child]+subTreeSize[child];
            }
        }
         subTreeAns[src]=ansNodes;
         subTreeSize[src]=noNodes;
        
    }
    
    void dfs(vector<int>adj[],int src,int par,vector<int>&subTreeSize,vector<int>&subTreeAns,int partial_ans,vector<int>&ans,int n){
        ans[src]=subTreeAns[src]+partial_ans+(n-subTreeSize[src]);
        for(auto child:adj[src]){
            if(child!=par){
                dfs(adj,child,src,subTreeSize,subTreeAns,ans[src]-subTreeAns[child]-subTreeSize[child],ans,n);
            }
        }
        
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>subTreeSize(n,0);
        vector<int>subTreeAns(n,0);
        preprocessing(adj,0,-1,subTreeSize,subTreeAns);
        vector<int>dis(n,0);
        dfs(adj,0,-1,subTreeSize,subTreeAns,0,dis,n);
        return dis;
    }
    */
      vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;

    }

    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};