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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* node, int &res){
        int inc = 1, dec = 1;
        //from child to cur, inc denotes increasing, dec denotes decreasing
        if (node->left != NULL){
            auto t = dfs(node->left, res);
            if (node->val == node->left->val + 1) inc = t.first + 1;
            if (node->val == node->left->val - 1) dec = t.second + 1;
        }
        if (node->right != NULL){
            auto t = dfs(node->right, res);
            if (node->val == node->right->val + 1) inc = max(inc, t.first + 1);
            if (node->val == node->right->val - 1) dec = max(dec, t.second + 1);
        }
        res = max(res, inc + dec - 1);
        return {inc, dec};
    }
};