class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] > 1) {
                return nums[i];
            }
        }
        return 0;
    }
};