class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans=0;
        m[0]=1;
        int sum=0;
        int rem=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(m.find(rem)!=m.end()){
                ans+=m[rem];
                m[rem]++;
            }
            else m[rem]++;
        }
        return ans;
    }
    long long mod=(1000000000 + 7);
    int numOfSubarrays(vector<int>& arr) {
        
        long long  count=0;
        long long  sum=0;
        
        int k=2;  
        int n=arr.size();
        unordered_map<int,int> mp;
        mp[0]=1; 
        
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
             int re=sum%k;
         
            
            if (mp.find(re)!=mp.end()){
                count=count + mp[re];
            }
            
            mp[re]++;
        }
