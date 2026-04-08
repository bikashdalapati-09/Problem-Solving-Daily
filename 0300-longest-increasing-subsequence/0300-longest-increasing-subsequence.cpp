class Solution {
public:
    int n;
    int solve(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp) {
        if (curr >= n) {
            return 0;
        }

        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }

        int take = 0;
        if (prev == -1 || nums[prev] < nums[curr]) {
            take = 1 + solve(nums, curr, curr + 1, dp);
        }
        int skip = solve(nums, prev, curr + 1, dp);

        return dp[prev+1][curr] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        int prev = -1;
        int curr = 0;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, prev, curr, dp);
    }
};