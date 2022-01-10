class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int ca=0,cb=0;
        string ans="";
        while(a>0 or b>0){
            if((ca<2 and a>=b) or (cb>=2 and b>=a) ){
                ans+='a';
                a--;
                ca++;
                cb=0;
            }
            else{
                ans+='b';
                b--;
                cb++;
                ca=0;
            }
        }
        return ans;
    }
};
