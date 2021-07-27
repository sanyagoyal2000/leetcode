class Solution {
public:
    int mySqrt(int x) {
  long long ans;        
  long long s=0,e=INT_MAX;
while(s<=e)
{
long long mid=s+((e-s)/2);
    if(mid*mid<=x)
    {
        ans=mid;
        s=mid+1;
    }
    else
        e=mid-1;
}
        return ans;
}
};
