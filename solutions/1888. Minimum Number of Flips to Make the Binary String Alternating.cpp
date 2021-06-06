class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int odd[n + 1];
        int even[n + 1];
        odd[0] = 0;
        even[0] = 0;
        for(int i = 0; i < n; i++){
            if (i % 2 != 0){
                odd[i + 1] = odd[i] + (s[i] == '1');
                even[i + 1] = even[i] +(s[i] == '0');
            }else{
                odd[i + 1] = odd[i] +(s[i] == '0' );
                even[i + 1] = even[i] + (s[i] == '1');
            }
        }
        int res = min(odd[n], even[n]);
        for(int i = 0; i < n; i++){
            if (n % 2 != 0){
                res = min(res,odd[n] - odd[i + 1] + even[i + 1]);
                res = min(res, even[n] - even[i + 1] + odd[i + 1]);
            }
        }
        return res;
        
    }
};
