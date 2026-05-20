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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        TreeNode* front;
        queue<TreeNode*> qe;
        qe.push(root);

        while (!qe.empty()) {
            int n = qe.size();

            while (n--) {
                front = qe.front();
                qe.pop();

                if (front->left)
                    qe.push(front->left);
                if (front->right)
                    qe.push(front->right);
            }
            ans.push_back(front->val);
        }
        return ans;
    }
};