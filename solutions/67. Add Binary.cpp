class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
string ans;
int n=a.length(),m=b.length();
int i=n-1,j=m-1;
while(i>=0||j>=0||carry)
{
int c1=i<0?0:(a[i]-'0');
int c2=j<0?0:(b[j]-'0');
int sum=c1+c2+carry;
string x;
if(sum==3){
x+="1";
carry=1;
}else if(sum==2){
x+="0";
carry=1;
}else if(sum==1){
x+="1";
carry=0;
}else{
x+="0";
carry=0;
}
i--;
j--;
ans=x+ans;
}
return ans;
        
    }
};
