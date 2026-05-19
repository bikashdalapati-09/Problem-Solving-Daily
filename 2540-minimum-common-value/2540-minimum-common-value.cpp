class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return nums[mid];
            }

            if (nums[mid] < target) {
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        for (auto i : nums1) {
            if (binarySearch(nums2, i)) {
                return i;
            }
        }

        return -1;
    }
};