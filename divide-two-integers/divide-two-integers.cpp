class Solution {
public:
int divide(int dividend, int divisor) {
        int negatives=0;
        long numerator=dividend, 
		     denominator=divisor, 
		     ans=0;
        
        if (numerator == INT_MIN && denominator == -1) 
            return INT_MAX;
        
        if(numerator < 0) 
            ++negatives, 
            numerator=abs(numerator);
        if(denominator < 0) 
            ++negatives, 
            denominator=abs(denominator);
        
        // like a binary search keep doubling divisor until just below remaining dividend
		// and subtract it.
		// e.g 45 / 5 = 40 + 5 = 5 * 8 + 5 * 1 => 5 * 2^3 + 5* 2^0 => binary(1001) => 9
        // 45 / 5 = 9
        for(int i=31; i >= 0; --i)
            if((denominator<<i) <= numerator)
                numerator -= (denominator<<i),
                ans       |= (1<<i);
		
        return (negatives & 1)
				?-ans
				: ans;
    
}
};