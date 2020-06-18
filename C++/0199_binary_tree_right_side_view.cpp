/**
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 * Input: [1, 2, 3, null, 5, null, 4]
 * Output: [1, 3, 4]
 * Explanation:
 *          1       <---
 *         / \
 *        2   3     <---
 *         \   \
 *          5   4   <---
 */

class Solution {
    private:
        void helper(TreeNode* root, int height, vector<vector<int>>& temp) {
            if (root == nullptr) return;

            if (temp[height].size() == 0)
                temp.push_back(vector<int>());

            temp[height].push_back(root->val);
            helper(root->left,  height + 1, temp);
            helper(root->right, height + 1, temp);
        }
    public:
        vector<int> rightSideView(TreeNode *root) {
            vector<int> res = {};
            vector<vector<int>> temp = {{}};
            int height = 0;

            helper(root, 0, temp);

            for (int i = 0; i < temp.size() - 1; i++)
                res.push_back(temp[i][temp[i].size() - 1]);

            return res;
        }
};
