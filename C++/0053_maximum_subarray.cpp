/*
 * Given an integer array nums, find the contiguous subarray(containing at least one number)
 * which has the largest sum and return its sum.
 *
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 *
 * Example 1:
 * Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * Output: 6
 *
 * Constraints:
 * 1 <= nums.length < 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 */
class Solution {
    public:
        int maxSubarray(vector<int>& nums) {
            int sum = 0, max = nums[0];

            for (int i = 0; i < nums.size(); i++) {
                sum = sum + nums[i];
                max = (sum> max) ? sum : max;
                sum = (sum < 0) ? 0 : sum;
            }

            return max;
        }
};
