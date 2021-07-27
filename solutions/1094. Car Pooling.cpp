class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int sum = 0;
        map<int, int> mp; 
        
        
        for(auto i: trips){
            mp[i[1]] += i[0]; // taking passengers.
            mp[i[2]] -= i[0]; // will drop off sum there.
        }
        
        for(auto i: mp){
            sum += i.second;
            
            if(sum > capacity)
                return false;
        }
        return true;
    }
};
