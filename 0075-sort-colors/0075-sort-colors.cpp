class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for (auto& i : nums) {
            if (i == 0)
                zero++;
            else if (i == 1)
                one++;
            else
                two++;
        }

        int idx = 0;
        while (zero--) {
            nums[idx++] = 0;
        }
        while (one--) {
            nums[idx++] = 1;
        }
        while (two--) {
            nums[idx++] = 2;
        }
    }
};