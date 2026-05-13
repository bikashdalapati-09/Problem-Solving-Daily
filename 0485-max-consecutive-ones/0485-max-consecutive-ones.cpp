class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int ans = 0;

        while (i < nums.size()) {
            if (nums[i] == 0) {
                count = 0;
                i++;
            } else {
                count++;
                ans = max(ans, count);
                i++;
            }
        }
        return ans;
    }
};