class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;
        for (auto qi : queries) {
            int element = nums[qi];
            auto& vec = mp[element];

            int len = vec.size();
            if (len == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(vec.begin(), vec.end(), qi) - vec.begin();
            int res = INT_MAX;

            int right = vec[(pos + 1) % len];
            int d = abs(qi - right);
            int circularDist = n - d;
            res = min({res, d, circularDist});

            int left = vec[(pos - 1 + len) % len];
            d = abs(qi - left);
            circularDist = n - d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }
        return result;
    }
};