class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // support variables
        int len = gas.size(), curr = 0, total = 0, res = 0;
        // looking for the index
        for (int i = 0, n; i < len; i++) {
            n = gas[i] - cost[i];
            // updating res
            if (curr <= 0 && n > 0) {
                res = i;
                curr = 0;
            }
            curr += n;
            total += n;
        }
        return total >= 0 ? res : -1;
    }
};
