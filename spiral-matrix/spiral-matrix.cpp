class Solution {
public:
    #define pb push_back
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        //approach according to ques 
        //after a traversal shrink that particular row or col
        int i, sr = 0, sc = 0; //sr-> starting row, sc->starting col
        int row = matrix.size();
        if(row == 0)
            return {};
        
        int col = matrix[0].size();
        vector<int> ans;
        while (sr < row && sc < col) 
        { 
            /* push the first row from 
                   the remaining rows */
            for (i = sc; i <= col-1; i++) 
                ans.pb(matrix[sr][i]);
            
            sr++; 

            /* push the last column  
             from the remaining columns */
            for (i = sr; i <= row-1; i++) 
                ans.pb(matrix[i][col - 1]); 
            
            col--; 

            /* push the last row from  
                    the remaining rows */
            if (sr < row) 
            { 
                for (i = col - 1; i >= sc; i--) 
                    ans.pb(matrix[row - 1][i]);
                
                row--; 
            } 
            /* push the first column from 
                       the remaining columns */
            if (sc< col) 
            { 
                for (i = row - 1; i >= sr; i--) 
                    ans.pb(matrix[i][sc]);
            
                sc++; 
            } 
        }
        return ans;
    }
};