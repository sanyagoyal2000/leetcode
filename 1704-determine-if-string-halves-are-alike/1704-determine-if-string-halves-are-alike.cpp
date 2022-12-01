class Solution {
public:
    bool isVowel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U')return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        for(int i=0;i<s.size()/2;i++){
            if(isVowel(s[i]))c1++;
        }
        for(int i=s.size()/2;i<s.size();i++){
            if(isVowel(s[i]))c2++;
        }
        if(c1==c2)return true;
        return false;
    }
};