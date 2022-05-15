class Solution {
public:
    int find(vector<vector<int>>& nums, int k){
        int l = 0,h=nums.size()-1,re = -1;
        while(l<h){
            int m = l+(h-l)/2;
            if(nums[m][1]<k) {
                re = m;
                h=m;
            }
            else l=m+1;
        }
        return re;
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        int n = tiles.size();
        vector<int> start, end;
        for(vector<int> vec : tiles) {
            start.push_back(vec[0]);
            end.push_back(vec[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int total = 0;
        vector<int> pref(n);
        for(int i=0; i<n; i++) {
            total += end[i]-start[i]+1;
            pref[i] = total;
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int last = start[i]+carpetLen-1;
            
            if(end[n-1] <= last) {
                int curr = pref[n-1];
                if(i > 0)   curr -= pref[i-1];
                
                ans = max(ans, curr);
            }
            else {
                int pos = upper_bound(end.begin(), end.end(), last) - end.begin();
                int curr = pref[pos-1];
                if(i > 0)   curr -= pref[i-1];
                
                if(last >= start[pos])  curr += last-start[pos]+1;
                ans = max(ans, curr);
            }
        }
        
        return ans;
    }
