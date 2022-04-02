class Solution {
public:
    int minInsertions(string s) {
        stack<int>st;
        int c=0;
        int res=0;
        int i=0;
        int n=s.size();
        while(i!=n){
            if(s[i]=='('){
                st.push(i);
                i++;
            }
            else{
                if(s[i+1]==')'){
                    
                    if(!st.empty()){
                        st.pop();
                         i=i+2;
                    }
                    else{
                        res++;
                         i=i+2;
                    }
                   
                    }
                else{
                        if(!st.empty()){
                            st.pop();
                            res++;
                            i++;
                        }
                        else{
                            res+=2;
                            i++;
                        }
                        
                    }
                
                
            }
        }
        while(!st.empty()){
            st.pop();
            res+=2;
        }
        return res;
    }
};
