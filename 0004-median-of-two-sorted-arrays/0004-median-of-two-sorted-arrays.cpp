class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> arr(m + n);
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr[k++] = nums1[i];
                i++;
            } else {
                arr[k++] = nums2[j];
                j++;
            }
        }

        while (i < m) {
            arr[k++] = nums1[i];
            i++;
        }

        while (j < n) {
            arr[k++] = nums2[j];
            j++;
        }


        n = arr.size();
        if(n % 2 == 1){
            return arr[n/2];
        }
        return (arr[n/2] + arr[n/2 - 1]) / 2.00000;
    }
};