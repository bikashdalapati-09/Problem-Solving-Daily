class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int res = 0;

        for (int i = 0; i < n - 1; i++) {
            totalSum -= nums[i];
            int avg = totalSum / (n - i - 1);
            if (nums[i] > avg)
                res++;
        }
        return res;
    }
};