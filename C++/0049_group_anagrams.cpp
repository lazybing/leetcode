/**
 * Given an array of strings, group anagrams together.
 *
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *  ["ate", "eat", "tea"],
 *  ["nat", "tan"],
 *  ["bat"]
 * ]
 */

/*
 * Approach 1: Categorize by Sorted String
 * Intuition: Two strings are anagrams if and only if their sorted strings are equal.
 *
 * Algorithm:
 * Maintain a map ans:{string list} where each key K is sorted string, and each value
 * is the list of strings from the initial input that when sorted, are equal to K.
 * 
 * Such as {"aet":["ate", "eat", "tea"]}
 *
 * Complexity Analysis
 *  Time Complexity: O(NKlogK), where N is the length of strs, and K is the maximum 
 *  length of a string in strs. The outler loop has complexity O(N) as we iterate through
 *  each string. Then, we sort each string in O(KlogK) time.
 *  Space Complexity:O(NK), the total information content stored in res
 */
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            map<string, vector<string>> m;

            for (auto it = strs.begin(); it != strs.end(); it++) {
                string tmpstr = *it;
                sort(tmpstr.begin(), tmpstr.end());
                m[tmpstr].push_back(*it);
            }

            for (auto it = m.begin(); it != m.end(); it++)
                res.push_back(it->second);

            return res;
        }
};

/*
 * Approach 2: Categorize by Count
 * Intuition:
 *  Two strings are anagrams if and only if their character counts(
 *  respective number of occurrences of each character) are the same.
 *
 * Algorithm:
 *  We can transform each string s into a character count, count consisting of 
 *  26 non-negative integers representing the number of a's b's c's etc.
 *  We use these counts as the basis for our hash map.
 *
 * Complexity Analysis:
 *  Time Complexity:O(NK), where N is the length of strs, and K is the maximum length o
 *  a string in strs. Counting each string is linear in the size of the string, and we count
 *  every string.
 *  Space Complexity:O(NK), the total information content stored in ans.
 */
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            for (string s: strs) {
                mp[strSort(s)].push_back(s);
            }

            vector<vector<string>> res;
            for (auto p: mp)
                res.push_back(p.second);

            return res;
        }
    private:
        string strSort(string s) {
            int counter[26] = {0};
            for (char c: s)
                counter[c - 'a']++;

            string t;
            for (int c = 0; c < 26; c++)
                t += string(counter[c], c + 'a');

            return t;
        }
};

