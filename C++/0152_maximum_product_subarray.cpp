/**
 * Given an integer array nums, find the contiguous subarray within an array(contianing
 * at least one number) which has the largest product.
 *
 * Example 1:
 *  Input: [2, 3, -2, 4]
 *  Output: 6
 *  Explanation: [2, 3] has the largest product 6
 *
 * Example 2:
 *  Input: [-2, 0, -1]
 *  Output: 0
 *  Explanation: The result cannot be 2, because [-2, -1] is not a subarray.
 */

//Bruce Solution: Time Limit Exceeded
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int res = INT_MIN;

            for (int i = 0; i < nums.size(); i++) {
                int cur = 1;
                for (int j = i; j < nums.size(); j++) {
                    if (j == i)
                        cur = nums[i];
                    else
                        cur = nums[i] * cur;
                    res = max(cur, res);
                }
            }

            return res;
        }
};

//Dynamic Programming Solution
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            vector<int> mx(nums.size());
            vector<int> mn(nums.size());
            int res = mx[0] = mn[0] = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                mx[i] = max(max(mx[i - 1] * nums[i], mn[i - 1] * nums[i]), nums[i]);
                mn[i] = min(min(mx[i - 1] * nums[i], mn[i - 1] * nums[i]), nums[i]);
                res = max(mx[i], res);
            }

            return res;
        }
};
