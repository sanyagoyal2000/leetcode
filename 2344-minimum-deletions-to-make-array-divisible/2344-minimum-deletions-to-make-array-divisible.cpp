class Solution {
public:
    int smallest(set<int>&s,set<int>&st){
        for(auto e:s){
            bool flag=true;
            for(auto ele:st){
                if(ele%e>0)flag=false;
            }
            if(flag==true)return e;
            
        }
        return -1;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       map<int,int>m;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            s.insert(nums[i]);
        }
        set<int>st;
        for(int i=0;i<numsDivide.size();i++){
            st.insert(numsDivide[i]);
        }
        
        int sm=smallest(s,st);
                int ans=0;

        if(sm==-1)return -1;
        else{
            for(auto e:m){
                if(e.first<sm){
                    ans+=e.second;
                }
            }
        }
        return ans;
    }
};