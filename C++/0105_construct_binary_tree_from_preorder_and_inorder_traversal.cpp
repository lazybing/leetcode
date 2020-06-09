/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *  preorder = [3, 9, 20, 15, 7]
 *  inorder  = [9, 3, 15, 20, 7]
 *
 * Return the followint binary tree:
 *          3
 *         / \
 *        9  20
 *          /  \
 *         15   7
 */
class Solution {
    public:

        TreeNode *create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
            if (ps > pe)
                return nullptr;

            TreeNode *node = new TreeNode(preorder[ps]);
            int pos;
            for (int i = is; i <= ie; i++) {
                if (inorder[i] == node->val) {
                    pos = i;
                    break;
                }
            }

            node->left  = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
            node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);

            return node;
        }

        TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
            return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        }
};

