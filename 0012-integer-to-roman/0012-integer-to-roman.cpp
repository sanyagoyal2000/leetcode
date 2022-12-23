class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>>vp={{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        string ans="";
        int i=vp.size()-1;
        while(num>0 and i>=0){
            if(num>=vp[i].first){
                ans+=vp[i].second;
                num-=vp[i].first;
                
            }
            else i--;
        }
        return ans;
    }
};