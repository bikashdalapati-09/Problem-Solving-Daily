class Solution {
public:
    int n;
    int solve(vector<int>& nums, int prev, int curr) {
        if (curr >= n) {
            return 0;
        }

        int take;
        if (prev == -1 || nums[prev] < nums[curr]) {
            take = 1 + solve(nums, curr, curr + 1);
        }
        int skip = solve(nums, prev, curr + 1);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        int prev = -1;
        int curr = 0;

        return solve(nums, prev, curr);
    }
};