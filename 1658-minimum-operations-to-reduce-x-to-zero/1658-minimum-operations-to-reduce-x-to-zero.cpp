class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int rem = accumulate(nums.begin(), nums.end(), 0) - x;

        int i = 0;
        int j = 0;
        int sum = 0;
        int maxi = INT_MIN;

        while (j < n) {
            sum += nums[j];
            while (sum > rem && i <= j) {
                sum -= nums[i];
                i++;
            }
            if (sum == rem ) {
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi == INT_MIN ? -1 : (n - maxi);
    }
};