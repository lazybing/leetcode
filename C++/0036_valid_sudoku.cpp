/**
 * Determine if a 9x9 Sudoku board is valid.
 * Only the filled cells need to be validated according to the following rules:
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * Note:
 *  * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 *  * Only the filled cells need to be validated according to the mentioned rules.
 *  * The given board contain only digits 1-9 and the character '.'.
 *  * The given board size is always 9x9.
 */

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>> &board) {
            map<char, char> row[9], col[9], blk[9];
            char c;
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++) {
                    c = board[i][j];
                    if ((c != '.') &&
                        (0 < row[i][c]++ || 0 < col[j][c]++ || 0 < blk[i/3*3 + j/3][c]++))
                        return false;
                }
            return true;
        }
};


