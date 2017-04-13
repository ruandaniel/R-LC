/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int i){
        if (i == 1 && root->left == NULL && root->right == NULL) return root->val;
        int sum = 0;
        if (root->left != NULL) sum += helper(root->left, 1);
        if (root->right != NULL) sum += helper(root->right, 2);
        return sum;
    }
};