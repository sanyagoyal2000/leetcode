class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX,sum=0;
​
       for(int i=0,j=0;i<n;i++)
       {
        sum+=nums[i];   // 2+3+1+2=8>=7  // 3+1+2+4=10>=7 // 1+2+4  //2+4+3 //4+3
        while(sum>=target)  
        {
            ans=min(ans,i-j+1);  // i-j+1 -> window size //3-0+1=4  // again 4 // 3//3//2
            sum-=nums[j];       //for next window, exclude j // again exclude....
            j++;                // then move left pointer // again move.....
        }
       }
    if(ans==INT_MAX)
        return 0;
    return ans;  //2
    
}
};
