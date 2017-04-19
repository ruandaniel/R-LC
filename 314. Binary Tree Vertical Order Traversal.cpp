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
    //BFS
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<pair<TreeNode*, int>> q;   //node, column
        unordered_map<int, vector<int>> m;  //column, values
        q.push({root, 0});
        int l = 0, r = 0;
        while (!q.empty()){
            pair<TreeNode*, int> t = q.front();
            q.pop();
            int index = t.second;
            m[index].push_back(t.first->val);
            if (index > r) r = index;
            else if (index < l) l = index;
            if (t.first->left != NULL) q.push({t.first->left, index - 1});
            if (t.first->right != NULL) q.push({t.first->right, index + 1});
        }
        vector<vector<int>> res;
        for (int i = l; i <= r; i++) res.push_back(m[i]);
        return res;
    }
};