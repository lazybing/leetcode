/**
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them
 * is that adjacent house have security system connected and it will automatically
 * contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police
 *
 * Example 1:
 * Input: nums=[1, 2, 3, 1]
 * Output: 4 = 1 + 3
 */
class Solution {
    public:
        int rob(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            if (nums.size() == 1) return nums[0];
            if (nums.size() == 2) return max(nums[0], nums[1]);

            int size = nums.size();
            int dp[size];
            dp[0] = nums[0];
            dp[1] = max(nums[1], nums[0]);

            for (int i = 2; i < size; i++)
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

            return dp[size - 1];
        }
};
