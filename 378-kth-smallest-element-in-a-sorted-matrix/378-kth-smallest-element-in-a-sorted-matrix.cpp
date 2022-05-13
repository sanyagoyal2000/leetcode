class Solution {
public:
   int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];    // lowest element = first elemnt of mat, highest element = last element of mat
		// required element will be in between these to element
		// we can binary search in terms of condtion that how many number are less than the mid
        while(low < high){
            int mid = low + (high-low)/2;
            int cnt = 0;
            for(int i=0; i<n; i++){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            if(cnt < k){
                low = mid+1;
            }
            else high = mid;
        }
        return low;
    }
};