class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int open=intervals[0][0];
        int close=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(close>=intervals[i][0]){
                close=max(close,intervals[i][1]);
            }
            else{
                
                ans.push_back({open,close});
                open=intervals[i][0];
                close=intervals[i][1];
                
            }
        }
        ans.push_back({open,close});
        return ans;
    }
};