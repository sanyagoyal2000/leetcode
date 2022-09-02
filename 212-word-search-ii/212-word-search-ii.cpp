struct Node{
    bool flag=false;
    Node* links[26];
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* temp){
        links[ch-'a']=temp;
    }
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
};

class Trie{
    public: Node* root;
    Trie(){
        root=new Node();
    }
    
    void insert(string s){
        Node* temp=root;
        for(int i=0;i<s.length();i++){
            if(!temp->containsKey(s[i]))
                temp->put(s[i],new Node());
            temp=temp->get(s[i]);
        }
        temp->flag=true;
    }
    
    void search(vector<vector<char>> &board, Node* temp,int i,int j,vector<string>
    &ans,string s){
	//temp is the current node in the trie.
	// (i,j) is the current cell in the grid.
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || !temp || 
        board[i][j]=='*' || !temp->containsKey(board[i][j])) return;
        s+=board[i][j];
        Node* t=temp->get(board[i][j]);
        if(t->flag){
            ans.push_back(s);
            t->flag=false;
        }
        char ch=board[i][j];
        board[i][j] = '*'; //preventing this from getting reconsidered in same word
        search(board,temp->get(ch),i+1,j,ans,s); //bottom cell
        search(board,temp->get(ch),i,j+1,ans,s); //right cell
        search(board,temp->get(ch),i-1,j,ans,s); // top cell
        search(board,temp->get(ch),i,j-1,ans,s); //left cell
        board[i][j]=ch; //restoring original character
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string s:words) trie.insert(s);
        vector<string> ans;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                trie.search(board,trie.root,i,j,ans,"");
        return ans;
    }
};