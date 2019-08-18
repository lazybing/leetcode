// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * Given a string, find the length of the longest substring without repeating characters
 *
 * Examples:
 * Input        Output       Explanation
 * "abcabcbb"     3          substr:"abc", len is 3
 * "bbbbb"        1          substr:"b", len is 1
 * "pwwkew"       3          substr:"wke", len is 3
 *
 * Test Case && Boundary Test:
 * 1. Test If the input string is empty.
 * 2. Some special cases: all characters in the string is unique/same
 *
 * Think more:
 * 1. how the sliding window algorithm used in this problem
 * 2. what are the time&space complexity in each solutions
 *
 * Summary:
 * 1. for the sliding window the boundary condition is (right < themostright && left + win_len < themostright)
 * 2. the usage between unordered_set and unordered_map
 * 3. the usage between mapping.insert({key, val}) and mpaping[key] = val
 * 4. the commonly used table int[26] for letters 'a'-'z' and 'A'-'Z' int [128] for ASCII and int[256] for extended ASCII
 */

/*
 * Brute Force Solution
 * Time complexity:O(n^3)
 * Space complexity:O(min(n, m)), O(k) k is the sizeof mapping
 * Note: when the input string is large, time limit exceeded
 */
class Solution1 {
    private:
        bool allUnique(string s){
            unordered_map<char, int> mapping;
            for (int i = 0; i < s.size(); i++) {
                if (mapping.find(s[i]) == mapping.end())
                    mapping.insert({s[i], 1});
                else
                    return false;
            }
            return true;
        }
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0;
            for (int i = 0; i < s.size(); i++)
                for (int j = i; j < s.size(); j++)
                    if (allUnique(s.substr(i, j - i + 1)))
                        res = max(res, j - i + 1);
                    else
                        break;

            return res;
        }
};


/*
 * Sliding Window using unordered_set Solution
 * Time complexity:O(n^2)
 * Used time: 628ms
 */
class Solution2 {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            unordered_set<char> setting;

            for (left = 0; left < s.size(); left++) {
                right = left;
                while (right < s.size()) {
                    if (setting.find(s[right]) != setting.end()) { //has the char
                        break;
                    } else { // donnot has the char
                        setting.insert(s[right]);
                        res = max(res, right - left + 1);
                        right++;
                    }
                }
                setting.clear();
            }

            return res;
        }
};

/*
 * Sliding Window using unordered_set Solution
 * Time complexity:O(n^2)
 * Used time: 28ms
 */
class Solution3{
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            unordered_set<char> setting;

            while (right < s.size()) {
                if (setting.find(s[right]) != setting.end()) {
                    while(left < right) {
                        if (s[left] == s[right]) {
                            setting.erase(s[left]);
                            left++;
                            break;
                        } else {
                            setting.erase(s[left]);
                            left++;
                        }
                    }
                }
                setting.insert(s[right]);
                res = max(res, right - left + 1);
                right++;
            }
            return res;
        }
};

/*
 * Sliding Window using unordered_map Solution
 * Time complexity:O(n)
 * Used time: 8ms
 */
class Solution4 {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            unordered_map<char, int> mapping;
            while (right < s.size() && left + res < s.size()) {
                if (mapping.find(s[right]) != mapping.end()) {
                    left = max(left, mapping[s[right]] + 1);
                }
                mapping[s[right]] = right;
                right++;
                res = max(res, right - left + 1);
            }

            return res;
        }
}

/*
 * Sliding Window using ascii table Solution
 * Time complexity:O(n)
 * Used time: 12ms
 */
class Solution5 {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            int charset[256] = {-1};

            while (right < s.size() && left + res < s.size()) {
                left = max(left, charset[s[right]]);
                res  = max(res, right - left + 1);
                charset[s[right]] = right + 1;
                right++;
            }

            return res;
        }
};
