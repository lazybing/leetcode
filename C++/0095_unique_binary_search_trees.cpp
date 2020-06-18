/**
 * Given an integer n, generate all structurally unique BST's(binary search trees)
 * that store values 1...n.
 *
 * Example:
 * Input:3
 * Output:
 * [
 *  [1, null, 3, 2]
 *  [3, 2, null, 1]
 *  [3, 1, null, null, 2]
 *  [2, 1, 3]
 *  [1, null, 2, null, 3]
 * ]
 *
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 *      1            3      3       2       1
 *       \          /      /       / \       \
 *        3        2      1       1  3        2
 *       /        /        \                   \
 *      2        1          2                   3
 *
 * Constraints:
 * 0 <= n <= 8
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode():val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x):val(x), left(nullptr), right(nullptr){}
 *      TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
 * };
 */
class Solution {
    private:
        vector<TreeNode *>generateTree(int minval, int maxval){
            vector<TreeNode *> res;

            if (maxval < minval) {
                res.push_back(nullptr);
                return res;
            }

            for (int i = minval; i <= maxval; i++) {
                vector<TreeNode *>lefts  = generateTree(minval, i - 1);
                vector<TreeNode *>rights = generateTree(i + 1, maxval);

                for (int j = 0; j < lefts.size(); j++) {
                    for (int k = 0; k < rights.size(); k++) {
                        TreeNode *root = new TreeNode(i);
                        root->left  = lefts[j];
                        root->right = rights[k];
                        res.push_back(root);
                    }
                }
            }

            return res;
        }
    public:
        vector<TreeNode *> generateTrees(int n) {
            if (n == 0) return vector<TreeNode *>(0);

            return generateTree(1, n);
        }
};
