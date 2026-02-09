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
    TreeNode* solve(vector<int>& nums,int start,int end){
        if(start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        int elem = nums[mid];
        TreeNode* root = new TreeNode(elem);
        root -> left = solve(nums,start,mid - 1);
        root -> right = solve(nums,mid + 1,end);
        return root;
    }

    void solve(TreeNode *root,vector<int> &inorder){
        if(root == NULL){
            return;
        }
        solve(root -> left,inorder);
        inorder.push_back(root -> val);
        solve(root -> right,inorder);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        solve(root,inorder);
        int start = 0;
        int end = inorder.size() - 1;
        return solve(inorder,start,end);
    }
};