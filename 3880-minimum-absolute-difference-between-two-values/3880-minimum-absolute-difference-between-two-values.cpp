class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int maxi = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] != 0 && nums[j] != 0 &&
                    abs(nums[i] - nums[j]) >= 1) {
                    maxi = min(maxi, abs(i - j));
                }
            }
        }

        return (maxi == INT_MAX) ? -1 : maxi;
    }
};