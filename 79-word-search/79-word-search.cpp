class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int len)
    {
        // if all the characters in word is traversed or found in board
        if(len == word.size())
            return true;
        
        // first four conditions is for out of bound
        // and last conditions "board[i][j] != word[len])" is for if we will not found the first character in board
        // then directly return false
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[len])
            return false;
        
        // if we found the first character in board then store the charcter in temp
        char temp = board[i][j];
        
        // and mark that index as visited by storing some other value
        board[i][j] = '1';
        
        // then check for other characters in all 4 directions
        // and every time increase the len value by 1 to remember the length of word string
        bool found = dfs(board, word, i - 1, j, len + 1) ||  //up
                     dfs(board, word, i + 1, j, len + 1) ||  //down
                     dfs(board, word, i, j - 1, len + 1) ||  //left
                     dfs(board, word, i, j + 1, len + 1);    //right
        
        // then change the visited value by original character for other searches
        board[i][j] = temp;

        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                // first we have to search for first character of word string in board
                // then make a dfs call for other characters
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};
