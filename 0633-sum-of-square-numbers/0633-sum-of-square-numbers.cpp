class Solution {
public:
    bool judgeSquareSum(int c) {
        using ll = long long;

        ll i = 0;
        ll j = sqrt(c);

        while (i <= j) {
            ll temp = i * i + j * j;

            if (temp == c) {
                return true;
            }

            if (temp < c) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
};