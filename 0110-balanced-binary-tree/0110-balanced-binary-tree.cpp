/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool balancedOrNot = true;
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);

        if(balancedOrNot && abs(leftHeight - rightHeight) > 1){
            balancedOrNot = false;
        }



        int depth = max(leftHeight,rightHeight) + 1;
        return depth;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return balancedOrNot;
    }
};