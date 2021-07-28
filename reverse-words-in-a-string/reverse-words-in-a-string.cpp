class Solution {
public:
    string reverseWords(string s) {
       vector<string> words;
        int i=0;
        string word="";
        while(i<s.length())
        {
            if(s[i]!=' '){
                while(i<s.length()&&s[i]!=' ')
                {
                    word.push_back(s[i]);
                    i++;
                }
            }
            else{
                while(i<s.length()&&s[i]==' ')
                    i++;
            }
            if(word.length()!=0)
                   words.push_back(word);
            word="";  
        }
        for(i=words.size()-1;i>=0;i--)
        {
            word+=words[i];
            if(i!=0)
                word+=" ";
        }
        return word;
    }
};