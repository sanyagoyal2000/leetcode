class Solution {
public:
      int eraseOverlapIntervals(vector<vector<int>>& in) {
        function<bool(const vector<int>&, const vector<int>&)> comp = [&](const vector<int> &a, const vector<int> &b)->bool{
            return (a[0]==b[0])?(a[1]<b[1]):(a[0]<b[0]);
        }; 
        sort(in.begin(), in.end(), comp);
        int n=in.size(), b=in[0][1], count=0;
        for(int i=1; i<n; i++){
            if(in[i][0]>=b)
                b=in[i][1];
            else{
                count++;
                if(in[i][1]<b) b=in[i][1];
            }
        }
        return count;
    }
};