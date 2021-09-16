#define ll long long
class Solution {
public:
   static bool comp(pair<pair<ll,ll>,ll>&a, pair<pair<ll,ll>,ll>&b){
       if(a.first.first==b.first.first)
           return a.first.second<b.first.second;
       return a.first.first<b.first.first;
   } 
    
    ll binarySearch(vector<pair<pair<ll,ll>,ll>>&v, ll ending, ll s){
        ll e=v.size()-1;
        ll ans=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(v[m].first.first>=ending){
                ans=m;
                e=m-1;
            }
            else
                s=m+1;
        }
        return ans;
    }
    
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n=start.size();
        vector<pair<pair<ll,ll>,ll>>v;
        for(int i=0;i<n;i++){
            v.push_back({{(ll)start[i],(ll)end[i]},(ll)profit[i]});
        }
        sort(v.begin(),v.end(),comp);
        vector<ll>dp(n);
        //traversing from last job, dp[i]=profit made till job i
        dp[n-1]=v[n-1].second;
        ll prof;
        for(ll i=n-2;i>=0;i--){
            ll index=binarySearch(v,v[i].first.second,i);
            if(index==-1)
                prof=0;
            else
                prof=dp[index];
            dp[i]=max(dp[i+1],v[i].second+prof);
        }
        return dp[0];
    
    }
};