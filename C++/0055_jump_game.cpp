/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 *  Input: nums = [2, 3, 1, 1, 4]
 *  Output: true
 *  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Example 2:
 *  Input: nums = [3, 2, 1, 0, 4]
 *  Output: false
 *  Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 *
 * Constraints:
 *  1 <= nums.length <= 3 * 10 ^ 4
 *  0 <= nums[i][j]  <= 10^5
 */

class Solution{
    public:
        bool canJump(vector<int>& nums) {
           int max_len = 0;

           if (nums.size() == 1)  return true;

           for (int i = 0; i < nums.size(); i++) {
                if (i == max_len && nums[i] == 0)
                    return false;
                if (nums[i] + i >= nums.size() - 1)
                    return true;
                max_len = max(max_len, nums[i] + i);
           }

           return true;
        }

        bool canJump2(vector<int>& nums) {
            int n = nums.size();
            int maxReach = 0;

            for (int i = 0; i < n; i++) {
                if (maxReach < i)
                    return false;
                maxReach = max(maxReach, nums[i] + i);
            }

            return true;
        }
};
