class Solution {
public:
    int trap(vector<int>& heights) {
         if(heights.size()==0){
            return 0;
        }
        
        vector<int> ml;
        vector<int> mr;
        
        int maxi=heights[0];
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]);
            ml.push_back(maxi);
        }
        
        maxi=heights[heights.size()-1];
        for(int i=heights.size()-1;i>=0;i--){
            maxi=max(maxi,heights[i]);
            mr.push_back(maxi);
        }
        
        reverse(mr.begin(),mr.end());
        
        int ans=0;
        
        for(int i=0;i<heights.size();i++){
            ans=ans+(min(ml[i],mr[i])-heights[i]);
        }
        
        return ans;
    
        
    }
};