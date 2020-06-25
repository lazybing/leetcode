/**
 * Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j(i <= j) inclusive.
 *
 * Note:
 * A naive algorithm of O(n^2) is trivial. You MUST do better than that.
 *
 * Example:
 * Input: nums = [-2, 5, -1], lower = -2, upper = 2,
 * Output:3
 * Explanation: The three ranges are: [0,0],[2,2],[0,2] and their respective sums are: -2, -1, 2.
 */

//Time Limit Exceed
class Solutiono {
    public:
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            int res = 0;

            for (int i = 0; i < nums.size(); i++) {
                long int sum = 0;
                for (int j = i; j < nums.size(); j++) {
                    sum += nums[j];
                    if (sum <= upper && sum >= lower)
                        res++;
                }
            }

            return res;
        }
};
