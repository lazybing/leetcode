/**
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2]
 *     [3,4]
 *    [6,5,7]
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11(i.e. 2 + 3 + 5 + 1 = 11)
 *
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 */
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            if (triangle.size() == 0) return 0;
            if (triangle.size() == 1) return triangle[0][0];

            int res = INT_MAX;
            vector<vector<int>> dp = triangle;
            dp[0][0] = triangle[0][0];

            for (int i = 1; i < dp.size(); i++) {
                for (int j = 0; j < dp[i].size(); j++) {
                    if (j == 0)
                        dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    else if (j == dp[i].size() - 1)
                        dp[i][j] = dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][j];
                    else
                        dp[i][j] = min(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
                }
            }

            for (int i = 0; i < dp[dp.size() - 1].size(); i++)
                res = min(res, dp[dp.size() - 1][i]);

            return res;
        }
};
