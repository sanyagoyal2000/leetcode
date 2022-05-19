class Solution {
public:
    //int bs(vector<int>& nums, int target){
    
        
    int search(vector<int>& arr, int target) {
       int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target)return mid;
            if(arr[mid]>=arr[l]){
                if(target>=arr[l] and target<arr[mid]){
                    r=mid-1;
                }
                else{
                    l= mid+1;
                }
            }
            else{
                if(target<=arr[r] and target>arr[mid]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            
        }
        return -1;
    }
};