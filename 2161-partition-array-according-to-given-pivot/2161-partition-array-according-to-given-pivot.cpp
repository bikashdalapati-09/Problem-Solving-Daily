class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr1, arr2;
        int count = 0;
        for (int num : nums) {
            if (num < pivot) {
                arr1.push_back(num);
            } else if (num > pivot) {
                arr2.push_back(num);
            } else {
                count++;
            }
        }
        while (count > 0) {
            arr1.push_back(pivot);
            count--;
        }
        for (int it : arr2) {
            arr1.push_back(it);
        }
        return arr1;
    }
};