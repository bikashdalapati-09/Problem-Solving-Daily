class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int m = mat.size();
        int n = mat[0].size();

        if(m * n != r * c) {
            return mat;
        }

        int idx = 0;

        vector<int> temp(m * n);

        for(auto row : mat) {
            for(auto val : row) {
                temp[idx++] = val;
            }
        }

        idx = 0;

        vector<vector<int>> result(r, vector<int>(c));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                result[i][j] = temp[idx++];
            }
        }

        return result;
    }
};