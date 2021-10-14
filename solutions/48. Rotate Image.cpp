class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<int>> matRotated(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                matRotated[i][n - j - 1] = mat[j][i];
            }
        }
        return matRotated;
    }
};
