class Solution {
public:
    int mySqrt(int n) {
        int start = 0;
        int end = n;
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long square = static_cast<long long>(mid) * mid;

            if (square == n) {
                return mid;
            }

            else if (square < n) {
                ans = mid;
                start = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};