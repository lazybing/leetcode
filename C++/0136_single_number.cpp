/**
 * Given a non-empty array of integers, every element appears twice except for one. Find the single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 *
 * Example 1:
 * Input : [2, 2, 1]
 * Output: 1
 *
 * Example 2:
 * Input : [4, 1, 2, 1, 2]
 * Output: 4
 */

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map<int, int> m;

            for (int i = 0; i < nums.size(); i++)
                m[nums[i]]++;

            for (auto it = m.begin(); it != m.end(); it++)
                if (it->second == 1)
                    return it->first;

            return 0;
        }
};

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int result = 0;

            for (int i = 0; i < nums.size(); i++)
                result ^= nums[i];

            return result;
        }
};
