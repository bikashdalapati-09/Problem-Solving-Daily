class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        int result = 0;

        while (l <= r) {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;
            
            int mid = l + (r - l) / 2;

            if (nums[result] > nums[mid]) {
                result = mid;
            }
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[result];
    }
};