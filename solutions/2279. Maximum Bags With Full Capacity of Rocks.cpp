class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
               
        for(int i = 0 ; i< rocks.size() ; i++)
            rocks[i] = capacity[i]-rocks[i];
​
​
        sort(rocks.begin() , rocks.end());
​
        int i = 0;
        
        while(i<rocks.size())
        {
           if(additionalRocks - rocks[i] >= 0)additionalRocks -= rocks[i++];
           else return i;
        }
         
        return i;
    }
};
