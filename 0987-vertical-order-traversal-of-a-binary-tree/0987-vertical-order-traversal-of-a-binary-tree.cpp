/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> qe;
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        qe.push(make_pair(root, make_pair(0, 0)));
        while (!qe.empty()) {
            pair<TreeNode*, pair<int, int>> temp = qe.front();
            qe.pop();

            TreeNode* front = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            mp[hd][lvl].push_back(front->val);

            if (front->left) {
                qe.push(make_pair(front->left, make_pair(hd - 1, lvl + 1)));
            }

            if (front->right) {
                qe.push(make_pair(front->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        for (auto i : mp) {
            vector<int> ans;
            for (auto j : i.second) {
                sort(j.second.begin(), j.second.end());
                for (auto k : j.second) {
                    ans.push_back(k);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};