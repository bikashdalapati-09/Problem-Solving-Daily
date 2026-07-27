class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0;
        sort(nums.begin(),nums.end(),greater<int>());
        maxi = (nums[0] - 1) * (nums[1] - 1);
        return maxi;
    }
};