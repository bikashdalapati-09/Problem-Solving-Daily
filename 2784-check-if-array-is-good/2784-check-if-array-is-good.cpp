class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto i: nums){
            mp[i]++;
        }

        for(auto [key, val]: mp){
            if(key != n-1){
                if(val > 1) return false;
            }
        }

        sort(nums.begin(), nums.end());

        return (nums[n - 1] == n - 1) && (nums[n - 2] == n - 1 && mp[nums[n-1]] == 2);
    }
};