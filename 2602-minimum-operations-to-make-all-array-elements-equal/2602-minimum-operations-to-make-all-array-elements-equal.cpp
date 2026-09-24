class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> ans;

        for(long long query : queries) {
            int idx = upper_bound(nums.begin(), nums.end(), query) - nums.begin();

            long long lSum = prefix[idx];
            long long rSum = prefix[n] - prefix[idx];

            int l = idx;
            int r = n - idx;

            long long res = (query * l - lSum) + (rSum - query * r);

            ans.push_back(res);
        }

        return ans;
    }
};