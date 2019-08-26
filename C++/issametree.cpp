// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * Given two binary trees, write a function to check if they are the same or not
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 *
 * Example:
 * 1.one/both of the p and q are nullptr
 * 2.none of the p or q is nullptr
 * 3.p and q are the same tree
 * 4.p and q are not the same tree, maybe donot have the same structure or have the same structure with the different node value
 *
 * Test Case & Boundary Test:
 * 1. (p == nullptr && q == nullptr)/(p != nullptr && q == nullptr)/(p == nullptr && q != nullptr)
 * 2. examples
 *    1         1
 *   / \       / \
 *  2   3     2   3
 *    1         1
 *   /           \
 *  2             2
 *    1         1
 *   / \       / \
 *  2   1     1   2
 *
 * Think more:
 * 1. how does this problem used the depth-first search algorithm when using the tree structure?
 * 2. what are the application scenarios of the dfs algorithm?
 * 3. what is the difference between dfs and cfs algorithm?
 * 4. what is the time complexity and sapce complexity about this problem?
 */

/*
 * Time Complexity:O(N), N is a number of nodes in the tree, since one visits each node exactly once.
 * Space complexity:O(log(N)) in the best case of completely balanced tree and
 *                  O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.
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

