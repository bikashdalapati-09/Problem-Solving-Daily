class Solution {
public:
    int findPivot(vector<int>& nums, int n) {
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums, n);

        int idx = binarySearch(nums, 0, pivot - 1, target);

        if (idx != -1) {
            return idx;
        }

        idx = binarySearch(nums, pivot, n - 1, target);

        return idx;
    }
};