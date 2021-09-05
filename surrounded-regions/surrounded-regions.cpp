class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Go through boarder to find 'O'
        for(int i=0; i<rows; ++i) {
            BFS(board, i, 0, rows, cols);
            if(cols>1) BFS(board, i, cols-1, rows, cols);
        }
        for(int i=1; i<cols-1; ++i) {
            BFS(board, 0, i, rows, cols);
            if(rows>1) BFS(board, rows-1, i, rows, cols);
        }
        
        // Go through whole board and mark 'O' as 'X', 'D' as 'O'
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='D') board[i][j] = 'O';
            }
        }
    }
    
    void BFS(vector<vector<char>>& board, int i, int j, int rows, int cols) {
        if(board[i][j]!='O') return;
        else board[i][j] = 'D';
        
        queue<pair<int, int>> myQueue;
        myQueue.push(make_pair(i, j));
        
        while(!myQueue.empty()) {
            int x = myQueue.front().first;
            int y = myQueue.front().second;
            myQueue.pop();
            
            if(x+1<rows && board[x+1][y]=='O') {
                myQueue.push(make_pair(x+1, y));
                board[x+1][y] = 'D';
            }
            if(x-1>0 && board[x-1][y]=='O') {
                myQueue.push(make_pair(x-1, y));
                board[x-1][y] = 'D';
            }
            if(y+1<cols && board[x][y+1]=='O') {
                myQueue.push(make_pair(x, y+1));
                board[x][y+1] = 'D';
            }
            if(y-1>0 && board[x][y-1]=='O') {
                myQueue.push(make_pair(x, y-1));
                board[x][y-1] = 'D';
            }
        }
    }
};