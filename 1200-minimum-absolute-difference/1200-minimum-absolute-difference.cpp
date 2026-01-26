class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (mini >= nums[i + 1] - nums[i]) {
                mini = nums[i + 1] - nums[i];
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (mini == nums[i + 1] - nums[i]) {
                arr.push_back({nums[i], nums[i+1]});
            }
        }
        return arr;
    }
};