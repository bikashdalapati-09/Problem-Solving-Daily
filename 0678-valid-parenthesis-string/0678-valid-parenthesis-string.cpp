class Solution {
public:
    bool solve(string s, int idx, int count, vector<vector<int>> &dp){
        if(count < 0){
            return false;
        }

        if(idx == s.size()){
            return count == 0;
        }

        if(s[idx] == '('){
            return solve(s, idx + 1, count + 1, dp);
        }

        if(s[idx] == ')'){
            return solve(s, idx + 1, count - 1, dp);
        }

        if(dp[idx][count] != -1){
            return dp[idx][count];
        }

        bool open = solve(s, idx + 1, count + 1, dp);
        bool close = solve(s, idx + 1, count - 1, dp);
        bool empty = solve(s, idx + 1, count, dp);

        return dp[idx][count] = open || close || empty;
    }

    bool checkValidString(string s) {
        vector<vector<int>> dp(100, vector<int>(100, -1));
        return solve(s, 0, 0, dp);
    }
};