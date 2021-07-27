class Solution {
static bool compare(const string &a, const string &b){
    return a+b > b+a;
}
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        int flag = 0;
        for(auto x:nums){
            if(x!=0){
                flag = 1;
            }
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), compare);
        string ans;
        for(auto x: v){
            ans += x;
        }
        if(flag == 0){
            return "0";
        }
        return ans;
        
    }
};
