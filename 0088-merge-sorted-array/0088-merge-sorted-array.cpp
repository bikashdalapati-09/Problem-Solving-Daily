class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = 0;
        int i = 0;
        int j = 0;
        vector<int> nums(m + n);

        while (i < m && j < n) {
            if (nums1[i] > nums2[j]) {
                nums[idx++] = nums2[j];
                j++;
            } else {
                nums[idx++] = nums1[i];
                i++;
            }
        }
        while (i < m) {
            nums[idx++] = nums1[i++];
        }
        while (j < n) {
            nums[idx++] = nums2[j++];
        }
        nums1 = nums;
    }
};