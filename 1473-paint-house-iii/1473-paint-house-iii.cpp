class Solution
{
    long long dp[105][25][105];
    long long maxi = 1000000000;
    
    long long dfs(int i, int prev, int k, vector<int> &houses, vector<vector<int>> &cost, int m, int n)
    {
       // if k is negative that means this path doesn't give us an ans, where total neighbours is exactly target.
	   // Here total neighbours excedded the target, so we return maxi (meaning no ans found)
        if (k < 0)
            return maxi;
        
        if (i >= m)
        {
            if (k == 0)  // if array is finished && k==0 , means we have found a path with some cost, we don't want to add 
                return 0; // any thing now to total cost, so we return zero
            else
                return maxi; // Array is finished but we still have some neighbours to form, so ans is not possible
        }

        if (dp[i][prev][k] != -1)
            return dp[i][prev][k]; //if we have alreay calculated for a i,prev and k, we simply return it.
            
		// if a house was already painted	
        if (houses[i])
        {
            if (houses[i] != prev)
                k--; // if it was painted with same as prev colour, we decrease required neighbour 
            return dfs(i + 1, houses[i], k, houses, cost, m, n);
        }
        
		// now we check for all possible colours for a given i, and return the one with minium cost
        long long ans = maxi;
        for (int j = 0; j < n; j++)
        {
            if (j + 1 == prev)
                ans = min(ans, cost[i][j] + dfs(i + 1, j + 1, k, houses, cost, m, n));
            else if (j + 1 != prev)
                ans = min(ans, cost[i][j] + dfs(i + 1, j + 1, k - 1, houses, cost, m, n));
        }

        return dp[i][prev][k] = ans; // we return our ans
    }

public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {

        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 25; j++)
                for (int k = 0; k < 105; k++)
                    dp[i][j][k] = -1;
		// dp[i][j][k] will represent minimum cost if i-th house is painted with colour j, and
		// neighbours required including this one = target

        long long ans = dfs(0, 0, target, houses, cost, m, n);
        return ans == maxi ? -1 : ans;
    }
};