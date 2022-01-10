class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        int size = a + b + c;
        int A = 0, B = 0, C = 0;
        for(int i = 0; i < size; i++) {
            if ((a >= b && a >= c && A != 2) || (B == 2 && a > 0) || (C == 2 && a > 0)){
                res+="a";
                a--,A++,B = 0,C = 0;  
            }else if ((b >= a && b >= c && B != 2) || (A == 2 && b > 0) || (C == 2 && b > 0)){
                res+="b";
                b--,B++,A = 0,C = 0;
            }else if ((c >= a && c >= b && C != 2) || (B == 2 && c > 0) || (A == 2 && c > 0)){
                res+="c";
                c--,C++,A = 0,B = 0;  
            }
        }
        return res;
    }
};
