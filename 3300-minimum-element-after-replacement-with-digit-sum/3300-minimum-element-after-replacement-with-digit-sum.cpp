class Solution {
public:
    int solve(int num){
        int sum = 0;
        while(num){
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto i: nums){
            mini = min(mini, solve(i));
        }
        return mini;
    }
};