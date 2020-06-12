/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1.
 * compute how much water it is able to trap after raining.
 */

/*
 * Solution one:
 * Insetead of calculating area by height * width, we can think it in a cumulative way.
 * In other words, sum water amount of each bin(width = 1).
 *
 * Search from left to right and maintain a max height of left and right separately, which
 * is like a one-side wall of partial container.
 *
 * Fix the higher one and flow water from the lower part.
 *
 * For example, if current height of left is lower, we fill water in the left bin. Until
 * left meets right, we filled the whole container.
 */
class Solution {
    public:
        int trap(vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int res = 0, maxleft = 0, maxright = 0;

            while (left <= right) {
                if (height[left] <= height[right]) {
                    if (height[left] >= maxleft)
                        maxleft = height[left];
                    else
                        res += maxleft - height[left];

                    left++;
                } else {
                    if (height[right] >= maxright)
                        maxright = height[right];
                    else
                        res += maxright - height[right];
                    right--;
                }
            }

            return res;
        }
};
