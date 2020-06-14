/*
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing only 1's and return its area.
 *
 * Example:
 * Input:
 * [
 *  ["1", "0", "1", "0", "0"],
 *  ["1", "0", "1", "1", "1"],
 *  ["1", "1", "1", "1", "1"],
 *  ["1", "0", "0", "1", "0"],
 * ]
 * Output: 6
 */

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.size() == 0) return 0;

            int maxArea = 0;

            int **width = (int **)malloc(sizeof(int *) * matrix.size());
            for (int i = 0; i < matrix.size(); i++)
                width[i] = (int *)malloc(sizeof(int) * matrix[0].size());

            for (int row = 0; row < matrix.size(); row++) {
                for (int col = 0; col < matrix[0].size(); col++) {
                    //update width
                    if (matrix[row][col] == '1') {
                        if (col == 0) width[row][col] = 1;
                        else width[row][col] = width[row][col - 1] + 1;
                    } else {
                        width[row][col] = 0;
                    }

                    //record the min width
                    int minWidth = width[row][col];

                    //update to the up
                    for (int up_row = row; up_row >= 0; up_row--) {
                        int height = row - up_row + 1;
                        minWidth = min(minWidth, width[up_row][col]);
                        maxArea  = max(maxArea, height * minWidth);
                    }
                }
            }

            free(width);

            return maxArea;
        }
};

