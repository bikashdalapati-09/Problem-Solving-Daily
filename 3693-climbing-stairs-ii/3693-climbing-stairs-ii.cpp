class Solution {
public:
    int solve(int step, vector<int>& costs, vector<int>& dp) {
        if (step == 0)
            return 0;

        if (dp[step] != -1)
            return dp[step];

        int ans = INT_MAX;

        if (step - 1 >= 0) {
            ans =
                min(ans, solve(step - 1, costs, dp) + costs[step - 1] + 1 * 1);
        }

        if (step - 2 >= 0) {
            ans =
                min(ans, solve(step - 2, costs, dp) + costs[step - 1] + 2 * 2);
        }

        if (step - 3 >= 0) {
            ans =
                min(ans, solve(step - 3, costs, dp) + costs[step - 1] + 3 * 3);
        }

        return dp[step] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(n, costs, dp);
    }
};