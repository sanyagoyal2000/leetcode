class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        vector<int>pref(n);
        vector<int>prefr(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        prefr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefr[i]=prefr[i+1]+nums[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            
            if(i<k){
                sum+=nums[i];
                left[i]=sum;
            }
           else{
            sum+=nums[i]-nums[i-k];   
            left[i]=max(left[i-1],sum);
           }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            
            if(i+k>=n){
                sum+=nums[i];
                right[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i+k]; 
            right[i]=max(right[i+1],sum);
            }
        }
        
        //mid->start=k;
        //mid->end=n-k-1;
        int maxS=0;
        int mid=-1;
        int l=-1;
        int r=-1;
        for(int i=k;i<=n-2*k;i++){
            if(maxS<(left[i-1]+right[i+k]+pref[i+k-1]-pref[i-1])){
                maxS=left[i-1]+right[i+k]+pref[i+k-1]-pref[i-1];
                mid=i;
            }
        }
        int leftS=left[mid-1];
        int rightS=right[mid+k];
        for(int i=k-1;i<mid;i++){
            
            if(pref[i]-((i-k)>=0?pref[i-k]:0)==leftS){
                l=i-k+1;
                break;
            }
        }
    
    for(int i=mid+(2*k)-1;i<n;i++){
            
                if((pref[i]-pref[i-k])==rightS){
                r=i-k+1;
                break;
            
        }
    }    
    
    vector<int>ans(3,0);
        ans[0]=l;
        ans[1]=mid;
        ans[2]=r;
        return ans;
    }
    
};