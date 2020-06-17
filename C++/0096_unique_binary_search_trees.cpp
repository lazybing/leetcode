/**
 * Given n, how many structurally unique BST's(binary search trees) that store values 1...n?
 * 
 * Example:
 * Input: 3 Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *      1            3      3       2       1
 *       \          /      /       / \       \
 *        3        2      1       1  3        2
 *       /        /        \                   \
 *      2        1          2                   3
 */

//Pick up one number k as root node from 1 to n, and using [0, k - 1] and [k + 1, n] to
//build its left and right child tree respectively.
//
//using [0, k - 1] because 0 represents for null child tree,
//but also a situation to be considered. 
//If [0, k - 1] has m unique BST, and [k + 1, n] has n unique BST, the under this circumstance of
//number k as root, we have m * n unique BST.
class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1, 0);
            dp[0] = dp[1] = 1;

            for (int i = 2; i <= n; i++) {
                for (int j = 1; j < i; j++)
                    dp[i] = dp[j] * dp[i - j -1];
            }

            return dp[n];
        }
};

//rec solution
class Solution {
    private:
        int nums(int n, vector<int> &t) {
            if (t[n] > 0) return t[n];
            int ans = 0;

            for (int i = 0; i < n; i++)
                ans += nums(i, t) * nums(n - i - 1, t);

            t[n] = ans;

            return ans;
        }
    public:
        int numTrees(int n) {
            if (n <= 1) return 1;
            vector<int> t(n + 1, 0);
            t[0] = t[1] = 1;

            return nums(n, t);
        }
};
