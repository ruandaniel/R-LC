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
    //first, count the height; second, find the target subtree, using cur->right->right...>last lvl to check
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL) return 1; 
        //at least, height >= 1
        TreeNode *p = root;
        int height = 0, res = 0;
        while (p->left != NULL){
            res += (1 << height); //count nodes that are not last level
            height++;
            p = p->left;
        }
        res += bottomCount(root, height);
        return res;
    }
    
    int bottomCount(TreeNode* root, int height){
        if (height == 1){ //when only two levels
            if (root->left == NULL) return 0;
            else if (root->right != NULL) return 2;
            else return 1;
        }
        TreeNode* p = root->left;
        for (int i = 1; i < height; i++){
            p = p->right;
        }
        //if p != null (left subtree is not completed tree), go to left subtree
        //else, count nodes according to current subtree height and go to right subtree
        if (p == NULL) return bottomCount(root->left, height-1);
        else return (1 << (height-1)) + bottomCount(root->right, height-1);
    }
};

//T = O((logn)^2)