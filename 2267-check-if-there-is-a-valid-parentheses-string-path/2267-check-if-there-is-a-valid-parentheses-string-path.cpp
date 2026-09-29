class Solution {
public:
    int m, n;
    bool solve(vector<vector<char>>& grid, int i, int j, int count, vector<vector<vector<int>>> &dp){
        if (i >= m || j >= n) {
            return false;
        }

        count += (grid[i][j] == '(') ? 1 : -1;

        if (count < 0) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {
            return count == 0;
        }

        if(dp[i][j][count] != -1){
            return dp[i][j][count];
        }

        bool right = solve(grid, i, j + 1, count, dp);
        bool down = solve(grid, i + 1, j, count, dp);

        return dp[i][j][count] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
    m, vector<vector<int>>(n, vector<int>(m + n, -1))
);

        return solve(grid, 0, 0, 0, dp);
    }
};