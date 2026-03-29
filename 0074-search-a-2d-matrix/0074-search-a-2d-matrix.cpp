class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int totalSize = m * n;

        int left = 0;
        int right = totalSize - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / m;
            int col = mid % n;

            int curr = matrix[row][col];

            if (curr == target) {
                return true;
            }

            if (curr > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};