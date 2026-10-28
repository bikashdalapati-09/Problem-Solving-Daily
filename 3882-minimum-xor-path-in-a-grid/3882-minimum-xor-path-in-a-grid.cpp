class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j, int xr, vector<vector<vector<int>>> &dp){
        if(i >= m || j >= n){
            return INT_MAX;
        }

        xr ^= grid[i][j];

        if(i == m-1 && j == n-1){
            return xr;
        }

        if(dp[i][j][xr] != -1){
            return dp[i][j][xr];
        }


        int right = solve(grid, i, j+1, xr, dp);
        int down = solve(grid, i+1, j, xr, dp);

        return dp[i][j][xr] = min(right, down);
    }
    int minCost(vector<vector<int>>& grid) {
        int i = 0;
        int j = 0;

        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return solve(grid, i, j, 0, dp);
    }
};