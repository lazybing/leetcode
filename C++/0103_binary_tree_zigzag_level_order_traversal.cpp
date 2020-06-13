/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree [3, 9, 20, null, null, 15, 7],
 *          3
 *         / \
 *        9  20
 *          / \
 *         15 7
 *
 * return its zigzag level order traversal as:
 * [[3], [20, 9], [15, 7]]
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode():val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x): val(x), left(nullptr), right(nullptr){}
 *      TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
 * };
 */

class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            vector<vector<int>> res;
            vector<int> tmp;
            stack<TreeNode *> left2right;
            stack<TreeNode *> right2left;

            if (root == nullptr) return res;

            int l2r = 1, r2l = 0;
            left2right.push(root);

            while ((!left2right.empty()) || (!right2left.empty())) {
                if (l2r) {
                    while (!left2right.empty()) {
                        TreeNode *curr = left2right.top();
                        if (curr) tmp.push_back(curr->val);
                        if (curr->left)  right2left.push(curr->left);
                        if (curr->right) right2left.push(curr->right);
                        left2right.pop();
                    }

                    if (tmp.size() != 0) res.push_back(tmp);
                    tmp.clear();
                    l2r = 0;
                    r2l = 1;
                }

                if (r2l) {
                    while (!right2left.empty()) {
                        TreeNode *curr = right2left.top();
                        if (curr) tmp.push_back(curr->val);
                        if (curr->right) left2right.push(curr->right);
                        if (curr->left)  left2right.push(curr->left);
                        right2left.pop();
                    }

                    if (tmp.size() != 0) res.push_back(tmp);
                    tmp.clear();
                    r2l = 0;
                    l2r = 1;
                }
            }

            return res;
        }
};
