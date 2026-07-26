class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans_1 = 0;
        int ans_2 = 0;

        int n = nums.size() - 1;
        sort(nums.begin(),nums.end());
        ans_1 = nums[n] * nums[n - 1] * nums[n - 2];
        ans_2 = nums[0] * nums[1] * nums[n];
        return max(ans_1,ans_2);
    }
};