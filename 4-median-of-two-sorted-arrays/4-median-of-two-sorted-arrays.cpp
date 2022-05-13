class Solution {
public:
   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size()<nums1.size())return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size();
        int n=nums2.size();
            int l=0;
            int r=m;
            while(l<=r){
                int cut1=(l+r)/2;
                int cut2=(m+n+1)/2-cut1;
                 int l1=(cut1>0)?nums1[cut1-1]:INT_MIN;
                 int r1=(cut1<m)?nums1[cut1]:INT_MAX;
                int l2=(cut2>0)?nums2[cut2-1]:INT_MIN;
             int r2=(cut2<n)?nums2[cut2]:INT_MAX;
                if(l1<=r2 and l2<=r1){
                    return((m+n)%2==0)?((max(l1,l2)+min(r1,r2))/2.0):(max(l1,l2));
                }
                else if(l1>r2){
                    r=cut1-1;
                }
                else if(l2>r1){
                    l=cut1+1;
                }
            }
            return 0.0;
        }
    
};