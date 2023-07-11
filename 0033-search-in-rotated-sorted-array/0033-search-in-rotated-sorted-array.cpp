class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>=arr[l]){
                if(target>=arr[l] and target<arr[mid]  ){
                    r=mid-1;
                }
                else l=mid+1;
            }
            else{
                if(target>arr[mid] and target<=arr[r]){
                    l=mid+1;
                }
                else r=mid-1;
            }
            
        }
        return -1;
    }
};

