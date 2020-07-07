/**
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note:
 *  The same word in the dicionary may be reuese multiple times in the segmentation.
 *  You may assume the dictionary does not contain duplicate words.
 *
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * 
 * Example 3:
 *  Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 *  Output: false
 */
class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict;
            for (int i = 0; i < wordDict.size(); i++)
                dict.insert(wordDict[i]);

            vector<bool> flag(s.length() + 1, flase);
            flag[0] = true;

            for (int i = 1; i < s.length() + 1; i++) {
                for (int j = i; j >= 0; j--) {
                    if (flag[j] == true && dict.find(s.substr(j, i - j)) != dict.end()) {
                        flag[i] = 1;
                        break;
                    }
                }
            }

            return falg[s.length()];
        }
};
