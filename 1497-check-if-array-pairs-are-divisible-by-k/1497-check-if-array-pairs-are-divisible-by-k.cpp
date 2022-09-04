class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            int rem=arr[i]%k;
            if(rem<0)rem+=k;
            m[rem]++;
        }
        
        for(auto e:m){
            if(e.first==0){
                if(e.second%2==1)return false;
            }
            else if(m[k-e.first]!=e.second)return false;
        }
        return true;
    }
};
/*
0-2
1-2
2-2
3-2
4-2


*/