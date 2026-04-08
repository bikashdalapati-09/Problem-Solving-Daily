class Solution {
public:
    int n1, n2;
    int solve(string text1, string text2, int i, int j) {
        if (i >= n1 || j >= n2) {
            return 0;
        }

        int res = 0;
        if (text1[i] == text2[j]) {
            res = 1 + solve(text1, text2, i + 1, j + 1);
        } else {
            res = max(solve(text1, text2, i, j + 1),
                      solve(text1, text2, i + 1, j));
        }

        return res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size();
        n2 = text2.size();

        int idx1 = 0;
        int idx2 = 0;

        return solve(text1, text2, idx1, idx2);
    }
};