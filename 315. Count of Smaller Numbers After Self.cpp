class Solution {
public:
    struct Node{
        int val, less, dup; //less stores the number of nodes in left subtree of cur so far, dup stores the repeatance of cur
        Node *left, *right;
        Node(int v){
            val = v;
            less = 0; dup = 0;
            left = NULL; right = NULL;
        }
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        Node* root = new Node(nums.back());
        root->dup++;
        vector<int> res(1, 0);
        for (int i = nums.size()-2; i >= 0; i--){
            settle(nums[i], root, res, NULL, 0);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void settle(int v, Node* root, vector<int> &res, Node* pre, int less){
        if (root == NULL){ //if NULL, insert new node
            root = new Node(v);
            if (root->val < pre->val) pre->left = root;
            else pre->right = root;
        }
        if (v == root->val){ //if found, dup++, push into result
            res.push_back(less + root->less);
            root->dup++;
            return;
        } 
        pre = root;
        if (v < root->val){ //smaller than cur, cur's less++, go to left
            root->less++;
            root = root->left;
        }
        else{ //greater than cur, collect the number less, go to right
            less += root->less + root->dup;
            root = root->right;
        }
        settle(v, root, res, pre, less); //recursive
    }
};