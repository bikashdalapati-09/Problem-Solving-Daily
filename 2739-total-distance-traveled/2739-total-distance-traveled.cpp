class Solution {
public:
    int distanceTraveled(int maintank, int additionalTank) {
        int ans = 0;
        while (maintank) {
            if (maintank < 5)
                return ans + (maintank * 10);
            maintank -= 5;
            ans += 50;
            if (additionalTank > 0) {
                maintank++;
                additionalTank--;
            }
        }
        return ans;
    }
};