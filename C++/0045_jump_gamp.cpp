/*
 *  Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *  Each element in the array represents your maximum jump length at that position.
 *  Your goal is to reach the last index in the minimum number of jumps.
 *
 *  Example:
 *  Input:[2, 3, 1, 1, 4]
 *  Output:2
 *  Explanation: The minimum number of jumps to reach the last index is 2.
 *              Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *  Note:
 *  You can assume that you can always reach the last index.
 */
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size(), step = 0, start = 0, end = 0;
            while (end < n - 1) {
                step++;
                int maxend = end + 1;

                for (int i = start; i <= end; i++) {
                    if (i + numn[i] >= n - 1) return step;
                    maxend = max(maxend, i + nums[i]);
                }
                start = end + 1;
                end   = maxend;
            }

            return step;
        }

        int jump2(vector<int>& nums) {
            int far = 0, res = 0, MAX = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                MAX = max(MAX, i + nums[i]);
                if (far <= i) {
                    res++;
                    far = MAX;
                    MAX = 0;
                }
            }

            return res;
        }
};
