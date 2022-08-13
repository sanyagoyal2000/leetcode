#define pb push_back
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int>m;
        int sume=0;
        unordered_map<int,int>o;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                m[i]=nums[i];
                sume+=nums[i];
            }
            o[i]=nums[i];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int ind=queries[i][1];
            if(m.find(ind)!=m.end()){
                if(val%2==0){
                    sume+=val;
                    ans.pb(sume);
                    m[ind]+=val;
                }
                else{
                    sume-=m[ind];
                    ans.pb(sume);
                    o[ind]=m[ind]+val;
                    m.erase(m.find(ind));
                    
                }
            }
            else{
                if(val%2==0){
                    ans.pb(sume);
                    o[ind]+=val;
                }
                else{
                    sume+=o[ind]+val;
                    ans.pb(sume);
                    m[ind]=o[ind]+val;
                    o.erase(o.find(ind));
                    
                }
            }
        }
        return ans;
    }
};