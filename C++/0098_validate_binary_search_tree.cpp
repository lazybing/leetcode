/*
 * Given a binary tree, determine if it is a valid binary search tree(BST).
 *
 * Assume a BST is defined as follows:
 *  The left subtree of a node contains only nodes with keys less than the node's key.
 *  The right subtree of a node contains only nodes with keys greater than the node's key.
 *  Both the left and right subtrees must also be binary search trees.
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(): val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x):val(x), left(nullptr), right(nullptr){}
 *      TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
 * };
 */
class Solution {
    public:
        bool helper(TreeNode *node, long lower, long upper) {
            if (!node) return true;

            return lower < node->val && node->val < upper &&
                helper(node->left, lower, node->val) &&
                helper(node->right, node->val, upper);
        }

        bool isValidBST(TreeNode *root){
            return helper(root, LONG_MIN, LONG_MAX);
        }
};
