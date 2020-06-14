/*
 * Given a string which consists of lowercase or uppercase letters,
 * find the length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 *
 * Note:
 * Assume the length of given string will not exceed 1010.
 *
 * Example:
 * Input: "abccccdd" Output: 7
 * Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

class Solution {
    public:
        int longestPalindrome(string s) {
            int res = 0;
            int flag = 0;
            int casenum[52] = {0};

            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z')
                    casenum[s[i] - 'a']++;
                if (s[i] >= 'A' && s[i] <= 'Z') 
                    casenum[s[i] - 'A' + 26]++;
            }

            for (int i = 0; i < 52; i++) {
                if (casenum[i] %2 == 0) res += casenum[i];
                else {
                    if (!flag) {res += casenum[i]; flag = 1;}
                    else
                        res += casenum[i] - 1;
                }
            }

            return res;
        }
};
