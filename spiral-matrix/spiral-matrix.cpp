#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        if(row==0){
            return {};
        }
        vector<int>ans;
        int sr=0,sc=0;
        
        while(sr<row and sc<col){
            
            for(int i=sc;i<=col-1;i++){
                ans.pb(matrix[sr][i]);
                
            }
            sr++;
            
            for(int i=sr;i<=row-1;i++){
                ans.pb(matrix[i][col-1]);
            }
            
            col--;
            
            if(sr<row){
                for(int i=col-1;i>=sc;i--){
                    ans.pb(matrix[row-1][i]);
                }
                row--;
            }
            
             if(sc<col){
                for(int i=row-1;i>=sr;i--){
                    ans.pb(matrix[i][sc]);
                }
                sc++;
            }
            
            
        }
        return ans;
    }
};