class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int res=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            if(height[i]<=height[j]){
                ans=(j-i)*height[i];
                i++;
            }
            else{
                ans=(j-i)* height[j];
                j--;
            }
            res=max(ans,res);
        }
        return res;
    }
};