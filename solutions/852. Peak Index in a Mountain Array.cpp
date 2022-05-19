class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1])return mid;
            else if(arr[mid+1]>arr[mid])l=mid;
            else r=mid;
        }
        return -1;
    }
};
