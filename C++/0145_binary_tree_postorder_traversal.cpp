/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * Example:
 *  Input:  [1, null, 2, 3]
 *  Output: [3, 2, 1]
 *
 * Follow up:
 *  Recursive solution is trivial, could you do it iteratively?
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode():val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x): val(x), left(nullptr), right(nullptr){}
 *      TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
 * };
 */

//Recursive solution --- O(n) time and O(n) space
class Solution {
    private:
        void postorder(TreeNode *root, vector<int>& res) {
            if (root == nullptr) return;

            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;

            postorder(root, res);

            return res;
        }
};

//Iterative solution using stack -- O(n) time and O(n) space
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> nodes;
            stack<TreeNode *> todo;
            TreeNode *last = NULL;

            while (root || !todo.empty()) {
                if (root) {
                    todo.push(root);
                } else {
                    TreeNode *node = todo.top();
                    if (node->right && last != node->right) {
                        root = node->right;
                    } else {
                        nodes.push_back(node->val);
                        last = node;
                        todo.pop();
                    }
                }
            }

            return nodes;
        }
};

