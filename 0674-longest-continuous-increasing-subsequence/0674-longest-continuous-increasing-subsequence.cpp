class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();


        int count = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }

        ans = max(ans, count);

        return ans;
    }
};