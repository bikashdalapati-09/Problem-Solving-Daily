class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;
        int mini = INT_MAX;

        while (j < n) {
            if ((j - i + 1) == k) {
                int temp = nums[j] - nums[i];
                mini = min(mini, temp);
                i++;
            }
            j++;
        }
        return mini;
    }
};