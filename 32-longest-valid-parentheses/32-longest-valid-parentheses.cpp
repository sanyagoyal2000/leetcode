class Solution {
public:
    int longestValidParentheses1(string s) {
        int left =0, right=0, ans=0;
        for(int i=0;i<s.size(); i++){
            if(s[i]=='(') left++;
            else right++;
            if(left==right) ans=max(ans, 2*right);
            else if(right>=left)left=0, right=0;
        }
        left=0, right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') left++;
            else right++;
            if(left==right)ans=max(ans, 2*left);
            else if(left>=right)left=0, right=0;
        }
        return ans;
    }

int longestValidParentheses(string s) {
        int ans=0,sum=0;
        stack<int> st;
        st.push(-1);
        for(int i=0; i<s.size(); i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty()) st.push(i);
                else sum=i-st.top();
            }
            else st.push(i);
            ans=max(ans, sum);
        }
        return ans;
    }
};