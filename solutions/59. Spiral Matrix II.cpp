            }
            
            sr++; 
​
            /* push the last column  
             from the remaining columns */
            for (i = sr; i <= row-1; i++) 
            {
                matrix[i][col - 1] = count;
                count++;
            } 
            
            col--; 
​
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
