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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return subTrees(1, n);
    }
    //DFS, return all possible sub-trees
    vector<TreeNode*> subTrees(int l, int r){
        if (l > r) return {NULL};
        vector<TreeNode*> ret;
        for (int i = l; i <= r; i++){
            auto leftSub = subTrees(l, i-1);
            auto rightSub = subTrees(i+1, r);
            for (auto j : leftSub){
                for (auto k : rightSub){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = j;
                    cur->right = k;
                    ret.push_back(cur);
                }
            }
        }
        return ret;
    }
};