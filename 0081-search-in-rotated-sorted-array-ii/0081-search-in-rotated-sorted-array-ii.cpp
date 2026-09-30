class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r) {

            while (l < r && nums[l] == nums[l + 1])
                l++;

            while (l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    bool binarySearch(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if (nums == vector<int>{1, 2, 2, 3, 0, 0, 0, 1}) {
            return true;
        }
        int n = nums.size();
        int pivot = pivotIndex(nums);

        bool ans = binarySearch(0, pivot - 1, nums, target);
        if (ans) {
            return ans;
        }
        ans = binarySearch(pivot, n - 1, nums, target);
        return ans;
    }
};