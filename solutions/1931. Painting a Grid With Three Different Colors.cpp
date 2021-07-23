#define mod 1000000007
class Solution {
public:
    //red- 0 green -1 blue -2
   int memo[1000][1024] = {};
    int m, n, MOD = 1e9 + 7;
    int colorTheGrid(int m, int n) {
        this->m = m; this->n = n;
        return dp(0, 0, 0, 0);
    }
    int dp(int c, int prevColMask, int r, int curColMask) {
        if (c == n) return 1; // Found a valid way
        if (r == 0 && memo[c][prevColMask]) return memo[c][prevColMask];
        if (r == m) return dp(c + 1, curColMask, 0, 0);
        int ans = 0;
        for (int i = 1; i <= 3; ++i) // Try colors i in [1=RED, 2=GREEN, 3=BLUE]
            if (getColor(prevColMask, r) != i && (r == 0 || getColor(curColMask, r-1) != i))
                ans = (ans + dp(c, prevColMask, r + 1, setColor(curColMask, r, i))) % MOD;
        if (r == 0) memo[c][prevColMask] = ans;
        return ans;
    }
    int getColor(int mask, int pos) { // Get color of the `mask` at `pos`, use 2 bits to store a color
        return (mask >> (2 * pos)) & 3;
    }
    int setColor(int mask, int pos, int color) { // Set `color` to the `mask` at `pos`, use 2 bits to store a color
        return mask | (color << (2 * pos));
    }
};
