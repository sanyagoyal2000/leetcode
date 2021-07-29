class Solution {
public:
    
       vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        v[0].assign(1 , 1);
        if(numRows == 1) return v;
        v[1].assign(2 , 1);
        if(numRows == 2) return v;
        for(int i = 2 ;i<numRows;i++){
            v[i].assign(i+1 , 1);
            int k = 1;
            for(int j = 0 ;j<i-1;j++){
                v[i][k] = v[i-1][k-1]+v[i-1][k];
                k++;
            }
        }
        return v;
    }
    
};
