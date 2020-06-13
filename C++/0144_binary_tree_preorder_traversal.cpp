/*
 * Given a binary tree, return the preorder traversal of it's nodes' values.
 * Example:
 *  Input:  [1, null, 2, 3]
 *  Output: [1, 2, 3]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(): val(0), left(nullptr), right(nullptr){}
 *      TreeNode(int x): val(x), left(nullptr), right(nullptr){}
 *      TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
 * }
 */

//Recursive solution---O(n) time and O(n) sapce
class Solution {
    public:

        void rec(TreeNode *root, vector<int> &res) {
            if (root == nullptr) return;

            res.push_back(root->val);
            rec(root->left, res);
            rec(root->right, res);
        }

        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;

            rec(root, res);

            return res;
        }
};

//Iterative solution using stack -- O(n) time and O(n) space;
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            stack<TreeNode *> curr;
            vector<int> res;

            while (root || !curr.empty()) {
                if (root) {
                    res.push_back(root->val);
                    if (root->right)
                        curr.push(root->right);
                    root = root->left;
                } else {
                    root = curr.top();
                    curr.pop();
                }
            }

            return res;
        }
};

//morris traversal --- O(n) time and O(1) space.
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> nodes;

            while (root) {
                if (root->left) {
                    TreeNode *pre = root->left;
                    while (pre->right && pre->right != root) {
                        pre = pre->right;
                    }

                    if (!pre->right) {
                        pre->right = root;
                        nodes.push_back(root->val);
                        root = root->left;
                    } else {
                        pre->right = NULL;
                        root = root->right;
                    }
                } else {
                    nodes.push_back(root->val);
                    root = root->right;
                }
            }

            return nodes;
        }
};
