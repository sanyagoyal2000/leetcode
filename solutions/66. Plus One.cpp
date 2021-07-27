vector<int> plusOne(vector<int>& digits) {
        size_t currDig = digits.size() - 1;
        ++digits[currDig];
        
        // If we need to carry
        while(digits[currDig] == 10 && currDig > 0) {
            digits[currDig--] = 0;
            digits[currDig] += 1;
        }
        
        // If the first digit is 10 we need to create a new vector
        if (currDig == 0 && digits[0] == 10) {
            vector<int> newDigits{1, 0};
            for (size_t i = 0; i < digits.size() - 1; ++i) {
                newDigits.push_back(0);
            }
            return newDigits;
        }
        
        return digits;
    }
