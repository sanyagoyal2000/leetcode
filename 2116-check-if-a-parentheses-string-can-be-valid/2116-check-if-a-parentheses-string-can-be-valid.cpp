class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0) return false;
int open=0,close=0,unpaired=0,unlock=0;
for(int i=0;i<s.size();i++){
if(locked[i]=='0') unlock++;
else if(s[i]=='(') open++;
else if(s[i]==')') close++;
unpaired=close-open;
if(unpaired>unlock) return false;
}
open=0,close=0,unpaired=0,unlock=0;
for(int i=s.size()-1;i>=0;i--){
if(locked[i]=='0') unlock++;
else if(s[i]=='(') open++;
else if(s[i]==')') close++;
unpaired=open-close;
if(unpaired>unlock) return false;
}
return true;
    }
};