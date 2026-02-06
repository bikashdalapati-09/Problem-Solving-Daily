class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = 0;
        int newl = INT_MIN;

        while (i < n && j < n) {
            long long maxi = nums[j];
            long long mini = nums[i];
            if (maxi <= mini * k) {
                newl = max(newl, j - i + 1);
                j++;
            } else {
                i++;
            }
        }
        return n - newl;
    }
};