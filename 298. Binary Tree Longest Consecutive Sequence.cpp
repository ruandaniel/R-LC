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
        int res = 0;
        DFS(root, res, NULL, 0);
        return res;
    }
    
    void DFS(TreeNode* node, int &res, TreeNode* pre, int cur){
        if (node == NULL) return;
        if (pre == NULL || pre->val + 1 != node->val){
            cur = 1;
        }
        else cur++;
        if (cur > res) res = cur;
        DFS(node->left, res, node, cur);
        DFS(node->right, res, node, cur);
    }
};