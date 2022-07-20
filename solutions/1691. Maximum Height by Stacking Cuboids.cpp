class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboid) {
        // sorting the dimensions, ie [L,W,H]
        for(int i = 0; i<cuboid.size(); i++){
            sort(cuboid[i].begin(),cuboid[i].end());
        }
        // Sorting the cuboid vector, ie, lower dimensions first, using comparator fun
        sort(cuboid.begin(),cuboid.end(),comp);
        
        // This len will store the maxHeight so far for each index i
        vector <int> len(cuboid.size(),0);
        int h = 0, ans = 0;
        for(int i = 0; i<cuboid.size(); i++){
            len[i] = cuboid[i][2];
            for(int j = 0; j<i; j++){
            // Same OLD LIS stuff
                if(cuboid[i][0]>=cuboid[j][0] and cuboid[i][1]>=cuboid[j][1] and cuboid[i][2]>=cuboid[j][2]){
                    if(len[i]<len[j]+cuboid[i][2])
                        len[i] = len[j]+cuboid[i][2];
                }
            }
        }
        
        // Finding the maxHeight possible with any number of boxes
        for(auto u : len) ans = max(ans,u);
        return ans;
    }
protected:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0]){
            if(a[1]<b[1]) return true;
            else if(a[1]==b[1]){
                if(a[2]<b[2]) return true;
                return false;
            }
        }
        return false;
    }
};
