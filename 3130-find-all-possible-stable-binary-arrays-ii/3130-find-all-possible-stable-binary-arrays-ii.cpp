class Solution {
public:
    int M = 1e9 + 7;

    int solve(int i, int j, int last, int limit, vector<vector<vector<int>>>& dp) {

        if (i == 0 && j == 0) 
            return 0;

        if (j == 0) {
            if (last == 1) return 0; 
            return (i <= limit) ? 1 : 0;
        }

        if (i == 0) {
            if (last == 0) return 0; 
            return (j <= limit) ? 1 : 0;
        }

        if(dp[i][j][last] != -1){
            return dp[i][j][last];
        }


        int result = 0;

        if (last == 0) {
            result = (solve(i-1, j, 0, limit, dp) + solve(i-1, j, 1, limit, dp)) % M;

            if (i-1 >= limit)
                result = (result - solve(i-1-limit, j, 1, limit, dp) + M) % M;

        } else {
            result = (solve(i, j-1, 0, limit, dp) + solve(i, j-1, 1, limit, dp)) % M;

            if (j-1 >= limit)
                result = (result - solve(i, j-1-limit, 0, limit, dp) + M) % M;
        }

        return dp[i][j][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1, vector<int>(2, -1)));

        return (solve(zero, one, 0, limit, dp) + solve(zero, one, 1, limit, dp)) % M;
    }
};