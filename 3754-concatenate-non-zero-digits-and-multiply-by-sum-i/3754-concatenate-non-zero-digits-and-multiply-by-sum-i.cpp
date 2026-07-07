class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        string temp = "";
        long long sum = 0;

        for (auto& i : s) {
            if (i != '0') {
                temp += i;
                sum += i - '0';
            }
        }
        return stoll(temp) * sum;
    }
};