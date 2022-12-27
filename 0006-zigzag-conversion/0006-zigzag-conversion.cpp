class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        if(numRows==2){
             string even="";
             string odd="";
             for(int i=0;i<s.size();i++){
                 if(i%2==0){
                     even+=s[i];
                 }
                 else odd+=s[i];
             }
             return (even+odd);
         }
        vector<vector<char>>vp(numRows);
        int n=s.size();
        int d=numRows-2;
        bool flag=true;
        int cntb=0,cntd=0;
        for(int i=0;i<n;i++){
            if(flag==true){
                if(cntb<numRows){
                    vp[cntb].push_back(s[i]);
                    cntb++;
                }
                if(cntb==numRows){
                    cntb=0;
                    flag=false;
                }
            }
            else{
                if(cntd<d){
                    vp[numRows-2-cntd].push_back(s[i]);
                    cntd++;
                }
                if(cntd==d){
                    cntd=0;
                    flag=true;
                }
            }
        }
        string ans="";
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp[i].size();j++){
                ans+=vp[i][j];
            }
        }
        return ans;
    }
};

   /* 
    p     i      n
    a   l s    i g
    y a   h  r
    p     i
    
     
    */