class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int>q;
        int i;
        for( i=0;i<arr.size();i++){
            if(arr[i]!=0)q.push(arr[i]);
            else{ q.push(0);q.push(0);}
            int x=q.front();
            q.pop();
            arr[i]=x;
        }
      
    }
};