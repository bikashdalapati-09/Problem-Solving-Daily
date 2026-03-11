class Solution {
public:
    int findComplement(int num) {
        int count = 0;
        int result = 0;

        while(num){
            int rem = num % 2;
            result += (pow(2, count) * !rem);
            count++;
            num /= 2;
        }
        return result;
    }
};