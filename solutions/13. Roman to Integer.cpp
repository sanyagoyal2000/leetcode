class Solution {
public:
    int romanToInt(string s) {
        int res=0;
    int d=0;        
    
    map <char, int> letters;
    letters.insert({'I',1});
    letters.insert({'V',5});
    letters.insert({'X',10});
    letters.insert({'L',50});
    letters.insert({'C',100});
    letters.insert({'D',500});
    letters.insert({'M',1000});
​
    d=1;
    
    for (int i=0; i<s.length(); i++){
        
        if (i==s.length()-1)
            d=0;
        
        if (letters[s[i]] < letters[s[i+d]])
            res -= letters[s[i]];
        
        else if (letters[s[i]] >= letters[s[i+d]])
            res += letters[s[i]];
​
    }
    return res;
    }
};
