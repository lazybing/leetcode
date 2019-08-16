// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * Given an array of integers, return indices of tow numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example: given nums = [2, 7, 11, 15], target = 9
 * because nums[0] + nums[1] == 9;
 * return [0, 1]
 *
 * Test Case && Boundary Test : 
 * 1.nums empty  (nums = [], taregt = 9) return vector<int>{}
 * 2.only has one element (nums = [9], target = 9) return vector<int>{}
 * 3.no nums[i] + nums[j] == target (nums = [2, 7, 11, 15], target = 100) return vector<int>{}
 * 4.only the same element twice equals to target 2 * nums[i] == target (nums = [2, 7, 11, 15], taregt = 4) return vector<int>{}
 *
 * Think more: 
 * 1.If nums[2, 2, 7, 11, 15], target = 4, return [0, 1]. Because both nums[0] and nums[1] are equal to 2. Does this res have the same element twice?
 * 2.If the given array is sorted. Does it have a more efficency solution?
 * 3.If the given array has duplicated elements, how can you store the all solutions?
 *
 */
class Solution {
    public:
        /*
         * Brute Force Solution
         *
         * Time complexity: O(n^2)
         * Sapce complexity: O(1)
         */
        vector<int> twoSum1_ans1(vector<int>& nums, int target) {
            if (nums.size() <= 1)
                return vector<int>{};

            for (int i = 0; i < nums.size() - 1; i++)
                for (int j = i + 1; j < nums.size(); j++)
                    if (nums[i] + nums[j] == target)
                        return vector<int>{i, j};

            return vector<int>{};
        }

        /*
         * Two-pass Hash Table solution
         *
         * Time complexity: O(n)
         * Sapce complexity: O(n)
         */
        vector<int> twoSum_ans2(vector<int>& nums, int target) {
            unorderde_map<int, int> mapping;

            for (int i = 0; i < nums.size(); i++) {
                mapping.insert({nums[i], i});
                //mapping[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); i++) {
                auto j = mapping.find(target - nums[i]);
                if (j != mapping.end() && j->second != i)
                    return vector<int>{i, j->second};
            }

            return vector<int>{};
        }

        /*
         * One-pass Hash Table solution
         *
         * Time complexity: O(n)
         * Sapce complexity: O(n)
         */
        vector<int> towSum_ans3(vector<int>& nums, int target) {
            unorderde_map<int, int> mapping;
            for (int i = 0; i < nums.size(); i++) {
                mapping[nums[i]] = i;
                auto j = mapping.find(target - nums[i]);
                if (j != mapping.end() && j->second != i)
                    return vector<int> {i, j->second};
            }

            return vector<int>{};
        }
};
