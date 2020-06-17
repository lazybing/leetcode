/**
 * Given a complete binary tree, count the number of nodes.
 *
 * Note:
 * In a complete binary tree every level, except possibly the last, is completely filled,
 * and all nodes in the last level are as far left as possible.
 *
 * It can have between 1 and 2th nodes inclusive the last level h.
 *
 * Example:
 * Input:
 *          1
 *         / \
 *        2   3
 *       / \ / \
 *      4  5 6
 *
 *  Output:6
 */

//timespace O(n), touch every node if not equal to NULL, increase one
class Solution {
    private:
        int hasNode(TreeNode *node) {
            if (node == NULL)
                return 0;
            return 1 + hasNode(node->left) + hasNode(node->right);
        }
    public:
        int countNodes(TreeNode *root) {
            return hasNode(root);    
        }
};

class Solution {
    private:
        int countLastLevel(TreeNode *root, int height) {
            if (height == 1) {
                if (root->right != nullptr) return 2; 
                else if(root->left != nullptr) return 1;
                else return 0;
            }

            TreeNode *midNode = root->left;
            int currHeight = 1;
            while (currHeight < height) {
                currHeight++;
                midNode = midNode->right;
            }

            if (midNode == nullptr)
                return countLastLevel(root->left, height - 1);
            else
                return (1 << (height - 1)) + countLastLevel(root->right, height - 1);
        }
    public:
        int countNodes(TreeNode *root) {
            if (root == nullptr) return 0;
            else if (root->left == nullptr) return 1;

            int height = 0, nodesSum = 0;
            TreeNode *curr = root;

            while (curr->left != nullptr) {
                nodesSum += (1 << height);
                height++;
                curr = curr->left;
            }

            return nodesSum + countLastLevel(root, height);
        }
};
