class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long product = 1;
        long long temp = n;

        while(n){
            int rem = n % 10;

            sum += rem;
            product *= rem;

            n /= 10;
        }

        return temp % (sum + product) == 0 ? true : false;
    }
};