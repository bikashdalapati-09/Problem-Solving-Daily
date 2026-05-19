class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        bool flag = true;

        for(int i = 0; i < grid.size(); i++) {
            if(i % 2 == 1) {
                reverse(grid[i].begin(), grid[i].end());
            }

            for(int num : grid[i]) {
                if(flag) ans.push_back(num);
                flag = !flag;
            }
        }

        return ans;
    }
};