/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *  Input: [1, null, 2, 3]
 *  Output: [1, 3, 2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/**
 * Definition fro a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode():val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *      TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
 * };
 */

//Recursive solution 
//The first method to solve this problem is using recursion.
//This is the classical method and is straightforward.
//We can define a helper function to implements recursion.
//
//Complexity Analysis
//--Time complexity: O(n). The time complexity is O(n) because
//  the recursive function is T(n) = 2 * T(n / 2) + 1.
//--Space complexity: The worst case space required is O(n). and in the 
//  average case it's O(logn) where n is number of nodes.
class Solution {
    public:
        void rec(TreeNode *root, vector<int>& res) {
            if (root == nullptr)
                return;

            if (root->left) rec(root->left, res);
            res.push_back(root->val);
            if (root->right) rec(root->right, res);
        }

        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            rec(root, res);

            return res;
        }
};

// Iterating method using stack
// The strategy is very similiar to the first method, the different is using stack.
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> st;
            TreeNode *curr = root;

            while (curr != nullptr || !st.empty()) {
                while (curr != nullptr) {
                    st.push(curr);
                    curr = curr->left;
                }

                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }

            return res;
        }
};
