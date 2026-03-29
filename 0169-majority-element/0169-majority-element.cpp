class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int mej = nums[0];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (count == 0) {
                mej = nums[i];
                count = 1;
            } else if (nums[i] == mej) {
                count++;
            } else {
                count--;
            }
        }
        return mej;
    }
};