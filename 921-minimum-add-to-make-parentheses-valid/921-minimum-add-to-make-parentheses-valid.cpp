class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty())st.pop();
                else res++;
            }
        }
        while(!st.empty()){
            st.pop();
            res++;
        }
        return res;
    }
};