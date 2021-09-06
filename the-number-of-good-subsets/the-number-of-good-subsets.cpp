#define vi vector<int>
#define ll long long

ll mod = 1e9+7;
class Solution {
public:
    int numberOfGoodSubsets(vi& nums) {
        
        unordered_map<int, int>m;
        int ones = 0, res=0;
        
        int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        vi dp(1<<10, 0), tmp;
        dp[0] = 1; //everything is absent
        
        for(auto x:nums){
            if(x%4==0 || x%9==0 || x%25==0) continue;  //exclude square terms
            if(x==1) ones++;                           //special dealing
            else m[x]++;
        }
        
        for(auto x:m){
            
            //find current mask
            int curr_mask = 0;
            for(int i=0; i<10; i++)
                if(x.first%prime[i]==0) 
                    curr_mask+=(1<<i);
            
            //state updates
            tmp.assign(1<<10, 0);
            for(int mask=0; mask<(1<<10); mask++)
                if( (curr_mask & mask) ==0)
                    tmp[mask | curr_mask] = ((ll) dp[mask]*(ll) x.second)%mod;  //x.second is frequency
            
            //add tmp to dp
            for(int i=0; i<(1<<10); i++)
                dp[i] = (dp[i]+tmp[i] )%mod;
            
        }
        
        //remember to exclude empty set
        for(int i=1; i<(1<<10); i++) res =(res+dp[i] )%mod;
        
        //deal with ones
        while(ones--){
            res = ( (ll)res*2LL)%mod;
        }
        return res;
    }
};