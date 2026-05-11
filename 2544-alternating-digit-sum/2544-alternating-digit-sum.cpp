class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);

        int sum = 0;
        bool flag = true;

        for(auto i : s){
            sum += (flag ? (i - '0') : -(i - '0'));
            flag = !flag;
        }
        return sum;
    }
};