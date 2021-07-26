class Solution {
public:
    bool isSafe(vector<vector<char>>& b,int i, int j){
        if(i>=0 and j>=0 and i<b.size() and j<b[0].size())
            return true;
        else return false;
    }
    bool dfs(vector<vector<char>>& b, string word,int i,int j, int w,vector<vector<bool>>&visited){
        
        
        if(b[i][j]==word[w]){
           visited[i][j] = true;
            if(w == word.size() - 1)
                return true;
            if(isSafe(b,i-1,j) && visited[i-1][j] == false)
                if(dfs(b, word, i-1, j, w+1,visited))
                    return true;
            if(isSafe(b,i+1,j) && visited[i+1][j] == false)
                if(dfs(b, word, i+1, j, w+1,visited))
                    return true;
            if(isSafe(b,i,j-1) && visited[i][j-1] == false)
                if(dfs(b, word, i, j-1, w+1,visited))
                    return true;
            if(isSafe(b,i,j+1) && visited[i][j+1] == false)
                if(dfs(b, word, i, j+1, w+1,visited))
                    return true;
            visited[i][j] = false;
            return false;
        }
        
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0,visited))return true;
            }
           
        }
         return false;
    }
};