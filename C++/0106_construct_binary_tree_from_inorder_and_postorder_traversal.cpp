/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 *  You may assume that duplicates do not exist in the tree.
 *
 * For example, given:
 *  inorder   = [9, 3, 15, 20, 7]
 *  postorder = [9, 15, 7, 30, 3]
 *
 * Return the following binary tree:
 *          3
 *         / \
 *        9  20
 *          /  \
 *         15   7
 */

class Solution {
    public:
        TreeNode *create(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
            if (ps > pe)
                return nullptr;
            TreeNode *node = new TreeNode(postorder[pe]);
            int pos;
            for (int i = is; i <= ie; i++) {
                if (inorder[i] == node->val) {
                    pos = i;
                    break;
                }
            }
            node->left  = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
            node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);

            return node;
        }
        TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
            return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() = 1);
        }
};
