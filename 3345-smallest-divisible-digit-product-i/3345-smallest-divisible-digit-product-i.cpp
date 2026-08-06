class Solution {
public:
    bool solve(int n, int t){
        int mul = 1;
        while(n){
            int num = n % 10;
            mul *= num;
            n /= 10;
        }
        return mul % t == 0;
    }
    int smallestNumber(int n, int t) {
        while(n){
            if(solve(n, t)){
                return n;
            }
            n++;
        }
        return 0;
    }
};