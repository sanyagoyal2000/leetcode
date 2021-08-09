class Solution {
public:
    bool isValid(string S) {
        while(!S.empty())
    {
        size_t posn = S.find( "abc" );
        if( posn == string::npos )
            return 0;
        S.erase(posn, 3 );
    }
    return 1;
    }
};