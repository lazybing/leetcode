/**
 * Two elements of a binary search tree(BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Example 1:
 * Input: [1, 3, null, null, 2]
 *      1
 *     /
 *    3
 *     \
 *      2
 * Output: [3, 1, null, null, 2]
 *      3
 *     /
 *    1
 *     \
 *      2
 * Follow up:
 *  A solution using O(n) space is pretty straight forward.
 *  Could you devise a constant space solution?
 */

//The first error element is always larger than its next one while 
//the second element is always smaller than its previous one
class Solution {
    TreeNode *firstnode  = nullptr;
    TreeNode *secondnode = nullptr;
    TreeNode *prevnode   = new TreeNode(INT_MIN);
    private:
        void inorder(TreeNode *root) {
            if (root == nullptr) return;

            inorder(root->left);

            if (firstnode == nullptr && prevnode->val > root->val)
                firstnode = prevnode;

            if (firstnode != nullptr && prevnode->val > root->val)
                secondnode = root;

            prevnode = root;

            inorder(root->right);
        }
    public:
        void recoverTree(TreeNode *root) {
            //Inorder traversal to find the two elements
            inorder(root);

            //swap the values of the two nodes
            int temp = firstnode->val;
            firstnode->val  = secondnode->val;
            secondnode->val = temp;
        }
};
