class Solution {
public:
    double solve(double x, long long n) {
        if(n == 0){
            return 1;
        }

        double half = solve(x, n / 2);

        if(n % 2 == 0){
            return half * half;
        }

        return x * half * half;
    }

    double myPow(double x, int n) {
        long long num = n;

        if(num < 0){
            num = -num;
            return 1.0 / solve(x, num);
        }

        return solve(x, num);
    }
};