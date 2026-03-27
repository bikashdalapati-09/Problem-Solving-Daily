class Solution {
public:
    int m, n;
    void solve(vector<vector<int>>& dummy, int row, bool flag) {
        int temp = dummy[row][0];
        for (int col = 1; col < n; col++) {
            dummy[row][col - 1] = dummy[row][col];
        }
        dummy[row][n - 1] = temp;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>> dummy(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dummy[i][j] = mat[i][j];
            }
        }

        while (k--) {
            for (int i = 0; i < m; i++) {
                bool flag = (i % 2 == 0) ? false : true;
                solve(dummy, i, flag);
            }
        }

        return mat == dummy;
    }
};