class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        int n=nums2.size();
        map<int,int>m;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty())m[nums2[i]]=-1;
            else m[nums2[i]]=st.top();
            
            st.push(nums2[i]);
                
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};