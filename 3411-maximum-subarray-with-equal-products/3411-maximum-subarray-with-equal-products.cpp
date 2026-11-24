class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        long long prod = 1;
        int gd = 0, lm = 1;
        int ans = 1;

        while (j < n) {
            prod *= nums[j];
            gd = gcd(gd, nums[j]);
            lm = lcm(lm, nums[j]);

            while (i < j && prod != gd * lm) {
                prod /= nums[i];

                gd = 0;
                lm = 1;

                for (int k = i + 1; k <= j; k++) {
                    gd = gcd(gd, nums[k]);
                    lm = lcm(lm, nums[k]);
                }

                i++;
            }

            if (prod == gd * lm) {
                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};