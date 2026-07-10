class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0;
        int zero = 0;

        int maxO = 0;
        int maxZ = 0;

        for (char i : s) {
            if (i == '1') {
                one++;
                maxZ = max(maxZ, zero);
                zero = 0;
            } else {
                zero++;
                maxO = max(maxO, one);
                one = 0;
            }
        }
        maxZ = max(maxZ, zero);
        maxO = max(maxO, one);

        return maxO > maxZ;
    }
};