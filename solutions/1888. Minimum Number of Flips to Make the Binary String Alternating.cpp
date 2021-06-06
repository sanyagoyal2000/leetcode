        return res;
        
    }
};
/*
class Solution {
public:
    
    int mf(string &s, int n){
        int r1, r2;
        r1 = r2 = 0;
        int res = INT_MAX;
        vector<vector<int>> arr(s.size(), vector<int>(2, 0));
        for(int i = 0;i<s.size();i++){
            if(i%2 == 0){
                if(s[i] == '0')r1++;
                if(s[i] == '1')r2++;
            }else{
                if(s[i] == '1')r1++;
                if(s[i] == '0')r2++;
            }
            arr[i][0] = r1;
            arr[i][1] = r2;
            
            if( i + 1 >= n){
                if(i == n-1){
                    res = min(res,min(r1, r2));
                }else
                    res = min(res,min(r1 - arr[i-n][0], r2 - arr[i-n][1]));
            }
        }
        return res;
    }
    
    
    int minFlips(string s) {
        int n = s.size();
        s = s + s;
        return mf(s, n);
    }
};
*/
