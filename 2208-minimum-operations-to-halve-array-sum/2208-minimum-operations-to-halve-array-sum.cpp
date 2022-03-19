class Solution {
public:
    int halveArray(vector<int>& nums) {
        if(nums.size()==1)return 1;
        double sum=0;
        priority_queue<double>p;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=double(nums[i]);
            p.push(nums[i]);
        }
        double t=double(sum/2);
        
        while(sum>t){
            double num=p.top();
            p.pop();
                sum=sum-num +double(num/2);
                p.push(num/2);
                res++;
        }
        
        return res;
    }
};