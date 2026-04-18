class Solution {
public:
    int rev(int n) {
        int ans = 0;
        while (n) {
            int digit = n % 10;
            ans = ans * 10 + digit;
            n /= 10;
        }
        cout << ans;
        return ans;
    }
    int mirrorDistance(int n) {
        int mirror = rev(n);

        return abs(n - mirror);
    }
};