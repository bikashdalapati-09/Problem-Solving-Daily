class Solution {
public:
    bool solve(int num) {
        string s = to_string(num);
        int sum = 0;
        for (auto i : s) {
            sum += (i - '0');
        }
        return sum % 2 == 0;
    }
    int countEven(int num) {
        int count = 0;

        for (int i = 2; i <= num; i++) {
            if (solve(i)) {
                count++;
            }
        }
        return count;
    }
};