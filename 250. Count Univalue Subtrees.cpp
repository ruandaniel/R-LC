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
    int count = 0;
    int countUnivalSubtrees(TreeNode* root) {
        uni(root);
        return count;
    }
    
    bool uni(TreeNode* root){ //check two things: children all uni, cur value same as children
        if (root == NULL) return true;
        bool left = uni(root->left), right = uni(root->right);
        bool l = (root->left == NULL || root->left->val == root->val);
        bool r = (root->right == NULL || root->right->val == root->val);
        if (left && right && l && r){
            count++;
            return true;
        }
        else return false;
    }
};