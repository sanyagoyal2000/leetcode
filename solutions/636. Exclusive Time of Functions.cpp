class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int m=logs.size();
        stack <int> s;
        vector <int> ans(n,0);
        int last=0;
        for(int i=0;i<m;i++)
        {
            stringstream ss(logs[i]);
            string t1,t2,t3;
            getline(ss,t1,':');
            getline(ss,t2,':');
            getline(ss,t3,':');
            int id= stoi(t1);
            int time=stoi(t3);
            if(t2=="start")
            {
                if(!s.empty())
                {
                    ans[s.top()]+= time-last;
                }
                s.push(id);
                    last=time;
            }
            else
            {
                ans[s.top()]+=time+1-last;
                s.pop();
                last=time+1;
            }
        }
        return ans;
    }
};
