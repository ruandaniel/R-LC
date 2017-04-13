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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        if (p->right != NULL){
			p = p->right;
			while (p->left != NULL) p = p->left;
			return p;
		}
		else{
			TreeNode* target = NULL;
			while (root != NULL){
				if (p->val < root->val){
					target = root;
					root = root->left;
				}
				else if (p->val > root->val){
					root = root->right;
				}
				else break;
			}
			return target;
		}
    }

};