class Solution {
public:
    //this function stores sum of the subsequeces of provided vector into another vector
    void subsequenceSum(vector<int>&v,vector<long long>&store){
        long long ans = INT_MAX;
        for(int i=0;i<(1<<v.size());i++){
            long long sum = 0;
            for(int j=0;j<v.size();j++){
                if(i & (1<<j)) sum += v[j];
            }
           store.push_back(sum);
        }
    }
    
    //driver function
    int minAbsDifference(vector<int>& nums, int goal) {
        //divide array into two equal parts
        int n = nums.size();
        vector<int> v1,v2;
        for(int i=0;i<n/2;i++) v1.push_back(nums[i]);
        for(int i=n/2;i<n;i++) v2.push_back(nums[i]);
        
        //declaring sum vectors for both v1 and v2
        vector<long long> sum1,sum2;
        subsequenceSum(v1,sum1);
        subsequenceSum(v2,sum2);
        
        //sort sum2 to apply binary search
        sort(sum2.begin(),sum2.end());
        
        //now for each element in sum1 find the closest element to (goal - sum1[i]) in sum2
        long long ans = INT_MAX;
        for(int i=0;i<sum1.size();i++){
           int low = 0,high = sum2.size() - 1;
           while(low<=high){
               int mid = low + (high - low)/2;
               long long sum = sum1[i] + sum2[mid];
               
               ans = min(ans,abs(goal - sum));
               
               if(sum == goal) return 0;
               else if(sum < goal) low = mid + 1;
               else high = mid - 1;
           }
        }
        return ans;
    }
};