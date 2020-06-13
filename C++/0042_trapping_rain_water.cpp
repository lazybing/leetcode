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

/*
 * Solution two:
 * Indeed this question can be solved in one pass and O(1) space, but it's probably hard to caome up with in a short interview.
 * If you have read the stack O(n) solution for Largest Rectangle in Histogram, you will find this solution is very very similar.
 *
 * The main idea is: if we want to find out how much water on a bar(bot), we need to find out the left larger bar's index(il), and right larget bar's index(ir),
 * so that the water is (min(height[il], height[ir]) - height[bot]) * (ir - il - 1), 
 * use min since only the lower boundary can hold water, and we also need to handle the edge case that there is no il.
 *
 * To implement this we use a stack that store the indices with decreasing bar height,
 * once we find a bar who;s height is lareger, then left the top of the stack be bot,
 * the cur bar is ir, and the previous bar is il.
 */

class Solution {
    public:
        int trap(vector<int>& height) {
            stack<int> s;
            int max_water = 0, idx = 0;

            while (idx < height.size()) {
                if (s.empty() || height[idx] <= height[s.top()])
                    s.push(idx++);
                else {
                    int bot = height[s.top()];
                    s.pop();
                    if (s.empty())
                        max_water = 0;
                    else
                        max_water = (min(height[idx], height[s.top()]) - bot) * (idx - s.top() - 1);
                }
            }

            return max_water;
        }
};
