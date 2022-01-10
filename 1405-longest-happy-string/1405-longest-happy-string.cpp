class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //string res="";
        priority_queue<pair<int, char>> pq;
        if(a != 0) pq.push({ a, 'a' });
        if(b != 0) pq.push({ b, 'b' });
        if(c != 0) pq.push({ c, 'c' });
        char prev1 = '#';
        char prev2 = '#';
        string res;
        while(!pq.empty())
        {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            if(ch1 == prev1 && ch1 == prev2)
            {
                if(pq.empty()) return res;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                prev1 = prev2;
                prev2 = ch2;
                pq.push({ cnt1, ch1 });
                if(--cnt2 > 0) pq.push({ cnt2, ch2 });
            }
            else
            {
                prev1 = prev2;
                prev2 = ch1;
                res += ch1;
                if(--cnt1 > 0) pq.push({ cnt1, ch1 });
            }
        }
        return res;
    }
    
};

/*
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

};


*/