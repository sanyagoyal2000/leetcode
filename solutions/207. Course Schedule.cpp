class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& arr) {
        vector<int>adj[nc+1];
        int inc[nc+1];
        memset(inc,0,sizeof(inc));
        for(int i=0;i<arr.size();i++) 
        {
            adj[arr[i][1]].push_back(arr[i][0]);
            inc[arr[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<nc;i++)
        {
            if(inc[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            for(auto nbr:adj[tmp]){
                inc[nbr]--;
                if(inc[nbr]==0)q.push(nbr);
            }
            
        }
        for(int i=0;i<nc;i++)
        {
            if(inc[i]!=0) return false;
        }
        return true;
    }
};
