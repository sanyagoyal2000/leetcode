class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int i, j, n, res, txz, tyz;
        for (i = res = 0, n = grid.size(); i < n; i++) {
            for (txz = tyz = j = 0; j < n; j++) {
                if (grid[i][j])
                    res++;
                if (grid[i][j] > txz)
                    txz = grid[i][j];
                if (grid[j][i] > tyz)
                    tyz = grid[j][i];
            }
            res += txz + tyz;
        }
        return res;
    }
};
