class Solution {
public:
    long long getCompleted(vector<int>&arr,long long total){
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=total/arr[i];
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long minTime=0;
        long long maxTime=1LL*totalTrips*time[0];
        while(minTime<maxTime){
            long long mid=(maxTime+minTime)/2;
            if(getCompleted(time,mid)>=totalTrips){
                maxTime=mid;
            }
            else{
                minTime=mid+1;
            }
        }
        return minTime;
    }
};