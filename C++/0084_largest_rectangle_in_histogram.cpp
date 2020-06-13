/*
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * Example:
 * Input : [2, 1, 5, 6, 2, 3]
 * Output: 10
 */

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int left = 0, right = 0;
            int maxRec = 0;

            for (int left = 0; left < heights.size(); left++) {
                int minheight = heights[left];
                right = left;

                while (right < heights.size()) {
                    minheight = min(heights[right], minheight);
                    maxRec = max(maxRec, minheight * (right - left + 1));
                    right++;
                }
            }

            return maxRec;
        }
};

