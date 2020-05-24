/*
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 *
 * A subsequence of a string is a new string generated from the original string 
 * with some characters(can be non) deleted without changing the relative order of the remaining characters.
 * (eg. "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * A common subsequence fo two strings is a subsequence that is common to both strings.
 *
 * If there is no common subsequence, return 0.
 *
 * Example 1:
 *  Input : text1 = "abcde", text2 = "ace"
 *  Output: 3
 *  Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 * Example 2:
 *  Input: text1 = "abc", text2 = "abc"
 *  Output: 3
 *  Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 * Example 3:
 *  Input: text1 = "abc", text2 = "def"
 *  Output: 0
 *  Explanation: There is no such common subsequence, so the result is 0.
 *
 * Constraints:
 *  1 <= text1.length <= 1000
 *  1 <= text2.length <= 1000
 *  The input strings consists of lowercase English characters only.
 */

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<short>> m(text1.size() + 1, vector<short>(text2.size() + 1));

            for (auto i = 1; i <= text1.size(); i++)
                for (auto j = 1; j <= text2.size(); j++) {
                    if (text1[i - 1] == text2[j - 1])
                        m[i][j] = m[i - 1][j - 1] + 1;
                    else
                        m[i][j] = max(m[i - 1][j], m[i][j - 1]);
                }

            return m[text1.size()][text2.size()];
        }
};
