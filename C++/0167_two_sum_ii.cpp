// author: lazybing
// email: libinglimit@gmail.com
// github: https://github.com/lazybing

/*
 * Given an array of integers that is already sorted in ascending order,
 * find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2
 *
 * Note:
 * 1.Your returned answers(both index1 and index2) are not zero-based.
 * 2.You may assume that each input would have exactly one solution and
 *   you may not use the same element twice.
 *
 * Example:
 * Input: numbers = [2, 7, 11, 15], target = 9
 * Output: [1, 2]
 * Explanation: The sum of 2 and 7 is 9. Thereforce index1 = 1, index2 = 2
 *
 * Test Case && Boundary Test : 
 * 1.nums empty  (nums = [], taregt = 9) return vector<int>{}
 * 2.only has one element (nums = [9], target = 9) return vector<int>{}
 * 3.no nums[i] + nums[j] == target (nums = [2, 7, 11, 15], target = 100) return vector<int>{}
 * 4.only the same element twice equals to target 2 * nums[i] == target (nums = [2, 7, 11, 15], taregt = 4) return vector<int>{}
 *
 * Think more:
 * 1. Think about how to solve it if the array is not sorted.
 * 2. If the given array has duplicated elements, how can you store the all solution?
 * 3. Think why the pointer solution is ok. Prove it.
 *
 * Similar Questions:
 * 1. twosum
 *
 * Tag: two pointer && hash table && array
 */

class Solution {
    public:
        /*
         * Brute Force Solution
         *
         * Time complexity: O(n^2)
         * Space complexity: O(1)
         */
        vector<int>twoSum_brute_ans(vector<int>& numbers, int target) {
            vector<int> ret;
            for (int i = 0; i < numbers.size() - 1; i++) {
                for (int j = i + 1; j < numbers.size() - 1; j++) {
                    if (numbers[i] + numbers[j] == target) {
                        ret.push_back(i + 1);
                        ret.push_back(j + 1);
                    }
                }
            }
            return res;
        }

        /*
         * Tow Pointers Solution
         *
         * Time complexity: O(n)
         * Space complexity: O(1)
         */
        vector<int> twoSum_twopoint_ans(vector<int>& number, int target) {
            for (int left = 0, right = number.size() - 1; left < right) {
                if (numbers[left] + numbers[right] == target)
                    return vector<int>{left + 1, right + 1};    //because of the requirement that the index should not not zero-based 
                else if (numbers[left] + numbers[right] > target)
                    right--;
                else
                    left++;
            }
            return vector<int>{};
        }
};
