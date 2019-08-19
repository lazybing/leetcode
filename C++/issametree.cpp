// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * Given two binary trees, write a function to check if they are the same or not
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 */

class Solution {
    public:
        /*
         * Recursion Solution
         */
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == nullptr && q == nullptr) return true;
            if (p == nullptr || q == nullptr) return false;
            if (p->val != q->val) return false;

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
};

