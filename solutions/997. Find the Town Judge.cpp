class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       
        vector<int>e (n,0);
        vector<int>t(n,0);
        for(auto p:trust){
            int u=p[0]-1;
            int v=p[1]-1;
            e[u]++;
            t[v]++;
            
            
        }
        
        for(int i=0;i<n;i++){
            if(e[i]==0 and t[i]==n-1)return(i+1);
        }
        
        
        return -1;
    }
};
