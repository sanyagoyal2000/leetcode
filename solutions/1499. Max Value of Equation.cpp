//https://leetcode.com/problems/max-value-of-equation/discuss/710434/C%2B%2BJava-O(n)-minimalizm
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<vector<int>> dq;    //decreasing deque to find the max of yi-xi for every j (i<j)
        
        //push the points in this format for easy lookup (xi,yi-xi)
        dq.push_back({points[0][0],points[0][1]-points[0][0]});  
        int n = points.size();
        int maxVal = INT_MIN;
        
        for(int j=1;j<n;j++){
            
            /*pop up all those points from front which are out of k distance from j point
            Note that all the points in deque are also in ascending order wrt x
            */
            while(!dq.empty() && points[j][0]-dq.front()[0]>k) 
                dq.pop_front();
            
            if(!dq.empty()){   
                int val = dq.front()[1]+points[j][1]+points[j][0];  //front point has max (yi-xi)
                maxVal = max(maxVal,val);
            }
            
            int v = points[j][1]-points[j][0];
            while(!dq.empty() && dq.back()[1]<=v)  // pop all the points which have less yi-xi value
                dq.pop_back();
            dq.push_back({points[j][0],v}); // finally push this point in deque
        }
        
        return maxVal;
    }
};
