/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *  Input: [1, null, 2, 3]
 *  Output: [1, 3, 2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/**
 * Definition fro a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode():val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *      TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
 * };
 */

//Recursive solution 
class Solution {
    public:
        void rec(TreeNode *root, vector<int>& res) {
            if (root == nullptr)
                return;

            if (root->left) rec(root->left, res);
            res.push_back(root->val);
            if (root->right) rec(root->right, res);
        }

        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            rec(root, res);

            return res;
        }
};
