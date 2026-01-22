class Solution {
public:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int minIdx = -1;

            for (int i = 0; i + 1 < nums.size(); ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }

            vector<int> newNums;
            for (int i = 0; i < nums.size(); ++i) {
                if (i == minIdx) {
                    newNums.push_back(nums[i] + nums[i + 1]);
                    i++;
                } else {
                    newNums.push_back(nums[i]);
                }
            }

            nums = newNums;
            count++;
        }

        return count;
    }
};
