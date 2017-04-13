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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<pair<TreeNode*, int>> q;   //node, column
        unordered_map<int, vector<int>> m;  //column, values
        q.push({root, 0});
        int l = INT_MAX, r = INT_MIN;
        while (!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            m[temp.second].push_back(temp.first->val);
            l = min(l, temp.second);
            r = max(r, temp.second);
            if (temp.first->left != NULL) q.push({temp.first->left, temp.second - 1});
            if (temp.first->right != NULL) q.push({temp.first->right, temp.second + 1});
        }
        vector<vector<int>> res;
        for (int i = l; i <= r; i++) res.push_back(m[i]);
        return res;
    }
};