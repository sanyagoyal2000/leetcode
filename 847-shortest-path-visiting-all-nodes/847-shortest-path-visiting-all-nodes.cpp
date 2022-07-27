class Solution {
public:
      class tuple
    {
        public:
        int node; // on which current node we are standing
        int mask; // mask of that node
        int cost; // cost of path explore by this node
        tuple(int node, int mask, int cost)
        {
            this -> node = node;
            this -> mask = mask;
            this -> cost = cost;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int all=(1<<n) -1;
        queue<tuple>q;
        set<pair<int,int>>visited;
        
        //initially we dont know starting from which node will give shortest path so we insert all
        for(int i=0;i<n;i++){
            tuple newTuple=tuple(i,1<<i,1);
            q.push(newTuple);  
            visited.insert({i,1<<i});
        }
        while(!q.empty()){
            tuple curr=q.front();
            q.pop();
            if(curr.mask ==all){
                return (curr.cost) -1;
            }
            for(auto nbr:graph[curr.node]){
                int newMask=curr.mask;
                newMask=newMask | 1<<nbr;
                
                tuple newInsert=tuple(nbr,newMask,curr.cost +1);
                if(visited.find({nbr,newMask})==visited.end()){
                    visited.insert({nbr,newMask});
                    q.push(newInsert);
                }
            }
        }
        
        return -1;
    }
};