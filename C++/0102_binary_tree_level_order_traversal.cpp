/*
 * Given a binary tree, return the level order traversal of its nodes' values.(ie. from left to right, level by level)
 * 
 * For example:
 * Given binary tree [3, 9, 20, null, null, 15, 7]
 * return its level order traversal as:
 * [[3], [9, 20], [15, 7]]
 */

class Solution {
    private:
        void levelOrderRec(TreeNode *root, int height, vector<vector<int>> &res) {
            if (root == nullptr) return;

            if (res.size() == height)
                res.push_back(vector<int>());

            res[height].push_back(root->val);

            levelOrderRec(root->left,  height + 1, res);
            levelOrderRec(root->right, height + 1, res);
        }

    public:
        vector<vector<int>> levelOrder(TreeNode *root) {
            vector<vector<int>> res = {};

            levelOrderRec(root, 0, res);

            return res;
        }
};
