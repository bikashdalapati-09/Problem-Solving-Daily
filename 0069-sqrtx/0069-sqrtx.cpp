class Solution {
public:
    int mySqrt(int n) {
        long long start = 0;
        long long end = n;
        int ans = 0;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long square = mid * mid;

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