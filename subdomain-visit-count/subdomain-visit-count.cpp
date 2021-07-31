class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
       unordered_map<string,int>cnt;
        for(auto cp:cpdomains){
            int i=cp.find(" ");
            string n=cp.substr(0,i);
            int no=stoi(n);
            string s=cp.substr(i+1);
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    cnt[s.substr(i+1)]+=no;
                }
            }
            cnt[s]+=no;
        }
        vector<string>res;
        for(auto k:cnt){
            res.push_back(to_string(k.second)+" "+k.first);
        }
        return res;
    }
};

    