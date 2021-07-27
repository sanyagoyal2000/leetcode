class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int i, int j) {
        vector<vector<int>> vec;
        int p=16,t=rows*cols-1,h=1,v=1;
        vec.push_back({i,j});
        int direction=1;
        while(t){
            int a=h,b=v;
            while(a--){
                if(direction==1) j++;
                else j--;
                if((i>=0 && i<rows) && (j>=0 && j<cols)){
                    vec.push_back({i,j});
                    t--;
                }
            }
            h++;
            while(b--){
                if(direction==1) i++;
                else i--;
                if((i>=0 && i<rows) && (j>=0 && j<cols)){
                    vec.push_back({i,j});
                    t--;
                }
            }
            v++;
            direction=(direction+1)%2;
        }
        return vec;
    }
};
