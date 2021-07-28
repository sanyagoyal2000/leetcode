class Solution {
public:
    string multiply(string num1, string num2) {
        
       if(num1=="0" || num2=="0"){
            return "0";
        }
        
        int l1=num1.length();
        int l2=num2.length();
    
        vector<int>arr(l1+l2,0);
        int l3=l1+l2;
     
        
        int i=l2-1;
        int pf=0;
        
        while(i >= 0){
            
            int ival=num2[i]-'0';
            i--;
            
            int j=l1-1;
            int carry=0;
            int k=l3-1-pf;
            
            while(j>=0 || carry !=0){
                
                int jval=( j>=0 ? num1[j]-'0':0);
                j--;
                          
                int prod= ival * jval + carry + arr[k];
                int rem=prod%10;
                 carry=prod/10;
                 arr[k]=rem;
                  k--;                  
            }
            pf++;
   
        }
        // handling leading in the array
        
        string str="";
        bool flag=false;
        
        for(auto x:arr){
            if(x==0 && flag==false){
                continue;
            }
            else{
                
                flag=true;
                str+=to_string(x);
            }
        }
        
        return str;
    }
};
