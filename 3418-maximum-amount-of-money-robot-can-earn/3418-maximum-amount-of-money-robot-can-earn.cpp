class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& coins, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(i >= m || j >= n) return INT_MIN;

        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && k > 0) return 0;
            return coins[i][j];
        }

        if(dp[i][j][k] != INT_MIN){
            return dp[i][j][k];
        }

        int val = coins[i][j];

        int take = val + max(
            solve(coins, i+1, j, k, dp),
            solve(coins, i, j+1, k, dp)
        );

        int skip = INT_MIN;
        if(val < 0 && k > 0){
            skip = max(
                solve(coins, i+1, j, k-1, dp),
                solve(coins, i, j+1, k-1, dp)
            );
        }

        return dp[i][j][k] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(coins, 0, 0, 2, dp);
    }
};