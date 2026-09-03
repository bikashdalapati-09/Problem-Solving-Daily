class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;

        long long sum = 0;
        long long maxi = 0;
        int duplicate = 0;

        while (j < n) {
            sum += nums[j];
            mp[nums[j]]++;

            if (mp[nums[j]] == 2) {
                duplicate++;
            }

            if (j - i + 1 > k) {
                mp[nums[i]]--;
                sum -= nums[i];

                if (mp[nums[i]] == 1) {
                    duplicate--;
                }

                i++;
            }

            if (j - i + 1 == k && duplicate == 0) {
                maxi = max(maxi, sum);
            }

            j++;
        }

        return maxi;
    }
};