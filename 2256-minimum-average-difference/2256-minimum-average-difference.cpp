class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long>pref(n,0),suff(n,0);
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }
        //cout<<pref[n-1]<<endl;
        int ans=INT_MAX;
        //cout<<ans<<endl;
        int index=0;
        for(int i=0;i<n-1;i++){
            int avg=abs((pref[i]/(i+1))-(suff[i+1]/(n-i-1)));
            //ans=min(ans,avg);
            //cout<<pref[i]<<" "<<suff[i+1]<<" "<<ans<<endl;
             if(avg<ans){
            index=i;
            ans=avg;
        }

        }
       if(ans>(pref[n-1]/n)){
           return (n-1);
       }
        return index;
    }
};