class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        if(n==0)
            return {};
        
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int row = n;
        int col = n;
        int i, sr = 0, sc = 0;
        int count = 1;
        while (sr < row && sc < col) 
        { 
            /* push the first row from 
                   the remaining rows */
            for (i = sc; i <= col-1; i++) 
            {
                matrix[sr][i] = count;
                count++;
            }
            
            sr++; 

            /* push the last column  
             from the remaining columns */
            for (i = sr; i <= row-1; i++) 
            {
                matrix[i][col - 1] = count;
                count++;
            } 
            
            col--; 

            /* push the last row from  
                    the remaining rows */
            if (sr < row) 
            { 
                for (i = col - 1; i >= sc; i--) 
                {
                    matrix[row - 1][i] = count;
                    count++;
                }
                
                row--; 
            } 
            /* push the first column from 
                       the remaining columns */
            if (sc< col) 
            { 
                for (i = row - 1; i >= sr; i--) 
                {
                    matrix[i][sc] = count;
                    count++;
                }
            
                sc++; 
            } 
        }
        return matrix;        
    }
};