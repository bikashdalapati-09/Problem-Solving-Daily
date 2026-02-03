class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;

        bool inc_1 = false, dec = false, inc_2 = false;

        while (i < n - 1 && nums[i] < nums[i + 1]) {
            inc_1 = true;
            i++;
        }

        
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            dec = true;
            i++;
        }


        while (i < n - 1 && nums[i] < nums[i + 1]) {
            inc_2 = true;
            i++;
        }

        return inc_1 && dec && inc_2 && i == n - 1;
    }
};
