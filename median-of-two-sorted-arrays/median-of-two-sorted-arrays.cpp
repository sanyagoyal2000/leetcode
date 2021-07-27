class Solution {
public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int>& smaller = nums1.size() < nums2.size() ? nums1 : nums2;
      vector<int>& larger = nums1.size() < nums2.size() ? nums2 : nums1;
      auto begin = larger.begin();
      
      for(int n : smaller) {
        auto pos_iter = std::upper_bound(begin, larger.end(), n);
        begin = larger.insert(pos_iter, n);
      }
      
      if(larger.size() % 2 == 0) {
        const size_t iprev = larger.size()/2-1;
        const size_t inext = larger.size()/2;
        return 0.5*larger[iprev] + 0.5*larger[inext];
      } else {
        const size_t index = (larger.size()-1)/2;
        return larger[index];
      }
      return 0.0;
    }
};