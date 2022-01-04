class Solution {
public:
    int bitwiseComplement(int n) {
         if (n == 0) {
            return 1;
        }

        int answer = 0;
        int power = 1;
        while (n) {
            answer += ((1 - (n % 2)) * power);
            n /= 2;
            power *= 2;
        }

        return answer;
    }
};