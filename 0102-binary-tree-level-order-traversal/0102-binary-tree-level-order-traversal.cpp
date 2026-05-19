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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        vector<int> temp;
        queue<TreeNode*> qe;

        qe.push(root);
        qe.push(NULL);

        while (!qe.empty()) {
            TreeNode* dummy = qe.front();
            qe.pop();

            if (dummy == NULL) {
                ans.push_back(temp);
                temp.clear();

                if (!qe.empty()) {
                    qe.push(NULL);
                }
            } else {
                temp.push_back(dummy->val);

                if (dummy->left) {
                    qe.push(dummy->left);
                }
                if (dummy->right) {
                    qe.push(dummy->right);
                }
            }
        }

        return ans;
    }
};