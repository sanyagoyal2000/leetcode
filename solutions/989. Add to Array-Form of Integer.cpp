class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
          int n = a.size();
    
    // Vector to store the answer
    vector<int> answer;
    
    /* Start adding both the numbers from the end */
    
    int carry = 0;
    // As long as one of the number exists, keep adding them
    while(!a.empty() || k!=0)
    {
        // Get the last digits of both the numbers. If a vector has finished off, the last digit is zero
        int lastDigit_1 = a.empty() ? 0 : a.back();
        int lastDigit_2 = k%10;
        
        // Sum up the digits and add the carry
        int sum = lastDigit_1 + lastDigit_2 + carry;
        answer.push_back(sum%10);
        carry = sum/10;
        
        // Remove the last digits of both the numbers
        if(!a.empty()) a.pop_back();
        k = k/10;
    }
    
    // If the carry is remaining, add it
    if(carry!=0) answer.push_back(carry);
    
    // Reverse the answer, since we were summing up from the end
    reverse(answer.begin(), answer.end());
    
    // Return the answer in vector format
    return answer;
    }
};
