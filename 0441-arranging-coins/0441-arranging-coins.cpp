class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        
        int l = 0;
        int r = n;

        while(l <= r){
            int mid = l + (r-l)/2;
            
            long long temp = 1LL * mid * (mid + 1) / 2;
            if(temp <= n){
                count = mid;
                l = mid + 1;
            }

            else{
                r = mid - 1;
            }

        }

        return count;
    }
};