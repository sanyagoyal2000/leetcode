class Solution 
{
public:
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O')
        {
            return;
        }
        board[i][j]='#';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
    void solve(vector<vector<char>>& board) 
    {
        // traverse through all the boundaries
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,i,0);
            }
        }
        for(int i=0;i<board[0].size();i++)
        {
            if(board[board.size()-1][i]=='O')
            {
                dfs(board,board.size()-1,i);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            if(board[i][board[0].size()-1]=='O')
            {
                dfs(board,i,board[0].size()-1);
            }
        }
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O')
            {
                dfs(board,0,i);
            }
        }
        
        // now traverse through all the cells of the matrix and convert 'O' to 'X' and '#' to 'O'
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};