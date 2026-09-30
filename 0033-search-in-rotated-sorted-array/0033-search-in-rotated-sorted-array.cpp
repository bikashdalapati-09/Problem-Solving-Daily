class Solution {
public:
    int pivotIndex(vector<int>& nums, int target) {
        int n = nums.size();

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
    int binarySearch(int l, int r, vector<int>& nums, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = pivotIndex(nums, target);

        int ans = binarySearch(0, pivot - 1, nums, target);
        if(ans != -1){
            return ans;
        }
        ans = binarySearch(pivot, n - 1, nums, target);
        return ans;
    }
};