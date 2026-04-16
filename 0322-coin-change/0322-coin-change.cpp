class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int ans = INT_MAX;
        for(auto i : coins){
            if(amount >= i){
                ans = min(ans + 0LL, solve(coins, amount - i, dp) + 1LL);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans; 
    }
};