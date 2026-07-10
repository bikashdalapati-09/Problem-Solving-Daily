class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int zero = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == '0') {
                zero++;
            } else {
                break;
            }
        }
        cout << zero << endl;

        return num.substr(0, n - zero);
    }
};