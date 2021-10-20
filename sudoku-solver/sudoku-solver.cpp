class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int x,int y,int n,char ch){
        //same row
        for(int i=0;i<n;i++){
            if(board[i][y]==ch)return false;
        }
        for(int i=0;i<n;i++){
            if(board[x][i]==ch)return false;
        }
        //starting pnt (x/3)*3 (y/3)*3
        int s=(x/3)*3;
        int t=(y/3)*3;
        for(int i=s;i<s+3;i++){
            for(int j=t;j<t+3;j++){
                if(board[i][j]==ch)return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>>& board,int i,int j,int n){
        if(i==n){
            return true;
        }
        if(j==n){
            return solver(board,i+1,0,n);
        }
        if(board[i][j]!='.'){
            return solver(board,i,j+1,n);
        }
        for(char c = '1'; c <= '9'; c++){
            
            if (isSafe(board,i,j,n,c)){
                
                board[i][j]=c;
               if(solver(board,i,j+1,n))return true;
               board[i][j]='.';
            }
        }
         return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        solver(board,0,0,n);
       
        
    }
};