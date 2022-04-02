class Solution {
public:
    int minSwaps(string s) {
        stack<int>o;
       
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[')o.push(i);
            else{
                if(!o.empty()){
                    o.pop();
                }
                else res++;
            }
            
        }
        return (res+1)/2;
        
    }
};
