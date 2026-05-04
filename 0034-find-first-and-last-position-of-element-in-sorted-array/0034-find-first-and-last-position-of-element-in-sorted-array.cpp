
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 0 or target > nums[nums.size() - 1] or
            target < nums[0]) {
            return {-1, -1};
        }

        int ind1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ind2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        vector<int> ans;
        if (nums[ind1] == target) {

            ans.push_back(ind1);
            ans.push_back(ind2 - 1);

        }

        else {

            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};
