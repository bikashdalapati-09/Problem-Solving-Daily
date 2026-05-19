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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = LLONG_MIN;
        vector<long long> data;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> temp;

            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            long long total = 0;
            for(auto i: temp){
                total += i;
            }
            data.push_back(total);
        }
        if(data.size() < k){
            return -1;
        }
        sort(data.begin(), data.end(), greater<long long>());

        return data[k-1];
    }
};