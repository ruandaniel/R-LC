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
    TreeNode *m1 = NULL, *m2 = NULL, *pre = NULL;
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int t = m1->val;
        m1->val = m2->val;
        m2->val = t;
    }
    
    void inorder(TreeNode* root){
        if (root == NULL) return;
        inorder(root->left);
        if (!(pre == NULL || root->val > pre->val)){ 
            //first reverse, pre is target, second reverse, cur is target
            if (m1 == NULL) {
                m1 = pre;
            }
            m2 = root; 
            //if this appears only once, means consecutive two are the targets; if twice, update the m2
        }
        pre = root;
        inorder(root->right);
    }
};