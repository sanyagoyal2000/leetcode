class Solution {
public:
    unordered_map<int,int>m;
    void swap(vector<int>&row,int i,int j){
        int temp=row[i];
        row[i]=row[j];
        row[j]=temp;
        m[row[j]]=j;
        m[row[i]]=i;
    }
    int minSwapsCouples(vector<int>& row) {
        for(int i=0;i<row.size();i++){
            m[row[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<row.size();i+=2){
            int first=row[i];
            int second=first^1;
            if(second!=row[i+1]){
               cnt++;
                swap(row,i+1,m[second]);
            }
        }
        return cnt;
        
    }
};