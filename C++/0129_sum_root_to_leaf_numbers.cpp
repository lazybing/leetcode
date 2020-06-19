/**
 * Given a binary tree containing digits from 0-9 only,
 * each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123;
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 */

class Solution {
    private:
        int travel(TreeNode *node, int &sum) {
            if (node == nullptr) return;
            else sum += node->val;

            if (node->left == nullptr &&
                node->right == nullptr)
                return sum;

            int leftsum = sum * 10, rightsum = sum * 10;

            sum = travel(node->left, leftsum) + travel(node->right, rightsum);
        }

    public:
        int sumNumbers(TreeNode *root) {
            int sum = 0;

            travel(root, sum);


            return sum;
        }
};
