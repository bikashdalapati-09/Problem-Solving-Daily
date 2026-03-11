class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int count = 0;
        int result = 0;
        while(n){
            int rem = (n % 2) ? 0 : 1;
            result += (pow(2, count) * rem);
            count++;
            n /= 2;
        }
        return result;
    }
};