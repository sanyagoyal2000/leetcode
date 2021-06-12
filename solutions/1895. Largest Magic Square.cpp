class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
    int m = size(grid), n = size(grid[0]);
    for(int sz = min(m, n); sz > 1; sz--) {
        for(int row = 0; row <= m - sz; row++) {
            for(int col = 0; col <= n - sz; col++) {
                int row_sum = 0, col_sum = 0, diag_sum = 0, anti_diag_sum = 0;
                bool flg = true;
​
                for(int i = 0; i < sz; i++) row_sum += grid[row][col + i];
                for(int i = 0; i < sz; i++) col_sum += grid[row + i][col];
                for(int i = 0; i < sz; i++) diag_sum += grid[row + i][col + i];
                for(int i = 0; i < sz; i++) anti_diag_sum += grid[row + i][col + (sz-1) - i];
​
                if(diag_sum != anti_diag_sum || diag_sum != row_sum || diag_sum != col_sum) continue;
​
                for(int i = 1; i < sz; i++) {
                    int cur_row_sum = 0;
                    for(int j = 0; j < sz; j++) 
                        cur_row_sum += grid[row + i][col + j];
                    if(cur_row_sum != row_sum) {
                        flg = false;
                        break;
                    }
                }
                if(!flg) continue;
​
                for(int i = 0; i < sz; i++) {
                    int cur_col_sum = 0;
                    for(int j = 0; j < sz; j++) 
                        cur_col_sum += grid[row + j][col + i];
                    if(cur_col_sum != col_sum) {
                        flg = false;
                        break;
                    }
