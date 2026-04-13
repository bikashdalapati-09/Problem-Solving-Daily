class Solution {
public:
    int n1, n2;
    int solve(string a, string b, int i, int j, vector<vector<int>> &dp) {
        if (i >= a.length()) {
            return b.length() - j;
        }
        if (j >= b.length()) {
            return a.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if (a[i] == b[j]) {
            return solve(a, b, i + 1, j + 1, dp);
        } else {
            int first = 1 + solve(a, b, i + 1, j, dp);
            int second = 1 + solve(a, b, i, j + 1, dp);

            ans = min(first, second);
        }

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        n1 = word1.size();
        n2 = word2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(word1, word2, 0, 0, dp);
    }
};