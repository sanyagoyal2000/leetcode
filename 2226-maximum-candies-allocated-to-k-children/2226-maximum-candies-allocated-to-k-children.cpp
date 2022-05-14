class Solution {
public:
    typedef long long ll;
    
    bool solve(vector<int>& v, ll mid, ll k){
        int n = v.size();
        ll cnt = 0;
        for(int i=0;i<n;i++){
            cnt += (v[i]/mid);
            if(cnt>=k) return true;
        }
        return false;
    }
    
    // v is the candies vector.
    int maximumCandies(vector<int>& v, long long k) {
        int n = v.size();
		int mx = 0;
        for(int i=0;i<n;i++){
			mx = max(mx,v[i]);
        }
        
        ll low = 1, high = mx;
        ll ans = 0;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(solve(v,mid,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};