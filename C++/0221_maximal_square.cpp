/**
 * Given a 2D binary matrix filled with 0's and 1's.
 * find the largest square containing onley 1's and return its area.
 *
 * Example:
 * Input:
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1 
 * 1 0 0 1 0
 * Output: 4
 */
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int res = 0;
            if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
            const int M = matrix.size(), N = matrix[0].size();
            vector<vector<int>> dp(M, vector<int>(N, 0));

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == 0 || j == 0)
                        dp[i][j] = matrix[i][j] -'0';
                    else if (matrix[i][j] == '1')
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

                    res = max(res, dp[i][j]);
                }
            }

            return res * res;
        }
};
