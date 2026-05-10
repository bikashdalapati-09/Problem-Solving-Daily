class Solution {
public:
    int solve(vector<int>& nums, int prev, int curr, int target, vector<vector<int>>& dp) {
        if (prev == nums.size() - 1) {
            return 0;
        }

        if (curr >= nums.size()) {
            return INT_MIN;
        }

        if(dp[prev][curr] != -1){
            return dp[prev][curr];
        }

        int take = INT_MIN;
        if (abs(nums[curr] - nums[prev]) <= target) {
            take = 1 + solve(nums, curr, curr + 1, target, dp);
        }
        int skip = 0 + solve(nums, prev, curr + 1, target, dp);

        return dp[prev][curr] = max(take, skip);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = solve(nums, 0, 1, target, dp);

        return (ans < 0) ? -1 : ans;
    }
};