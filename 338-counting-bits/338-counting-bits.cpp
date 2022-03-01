class Solution {
public:
    int setBits(int n){
        int c=0;
        while(n!=0){
            if((n&1)>0){c++;}
           
            n=n>>1;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            
            int z=setBits(i);
            //cout<<z;
            res.push_back(z);
        }
        return res;
    }
};