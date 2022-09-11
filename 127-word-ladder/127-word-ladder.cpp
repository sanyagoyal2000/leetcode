class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        queue<string> q;
        if(beginWord==endWord){
            return 0;
        }
        if(st.find(endWord)==st.end()){
            return 0;
        }
        int m=beginWord.size();
        int ans=0;
        q.push(beginWord);
        
        //just use bfs here
        while(!q.empty()){
            ans++;
            int size=q.size();
            for(int i=0;i<size;i++){
                string str=q.front();
                q.pop();
                for(int j=0;j<m;j++){
                    char ch=str[j];
                    for(char c='a';c<='z';c++){
                        str[j]=c;
                        if(str==endWord){
                             return ans+1;
                        }
                        if(st.find(str)==st.end()){
                            continue;
                        }
                        st.erase(str);
                        q.push(str);
                    }
                    str[j]=ch;
                }
            }
        }
        return 0;
    }
};