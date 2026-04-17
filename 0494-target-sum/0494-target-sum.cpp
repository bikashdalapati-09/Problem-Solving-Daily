class Solution {
public:
    int solve(vector<int>& nums, int i, int currSum, int target, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return currSum == target ? 1 : 0;
        }

        if (dp[i][currSum + 1000] != -1) {
            return dp[i][currSum + 1000];
        }

        int plus = solve(nums, i + 1, currSum + nums[i], target, dp);
        int minus = solve(nums, i + 1, currSum - nums[i], target, dp);

        return dp[i][currSum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return solve(nums, 0, 0, target, dp);
    }
};