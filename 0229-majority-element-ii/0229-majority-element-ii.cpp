class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = NULL, num2 = NULL;
        int count1 = 0, count2 = 0;
        for (auto element : nums) {
            if (num1 == element) {
                count1++;
            } else if (num2 == element) {
                count2++;
            } else if (count1 == 0) {
                num1 = element;
                count1 = 1;
            } else if (count2 == 0) {
                num2 = element;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        int countMajority = floor(nums.size() / 3);
        count1 = 0, count2 = 0;
        for (auto element : nums) {
            if (num1 == element) {
                count1++;
            }
            else if (num2 == element) {
                count2++;
            }
        }
        if (count1 > countMajority) {
            result.push_back(num1);
        }
        if (count2 > countMajority) {
            result.push_back(num2);
        }
        return result;
    }
};