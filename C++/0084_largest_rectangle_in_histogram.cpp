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

class Solution {
    public:
        int largestRectangleArea(vector<int> & heights) {
            if (heights.size() == 0) return 0;

            int *leftLessMin  = new int[heights.size()];
            int *rightLessMin = new int[heights.size()];

            //search the left side, find the first column less than the curr
            leftLessMin[0] = -1;
            for (int i = 1; i < heights.size(); i++) {
                int left = i - 1;
                while (left >= 0 && heights[left] >= heights[i])
                    left = leftLessMin[left];
                leftLessMin[i] = left;
            }

            //search the right side, find the first column less than the curr
            rightLessMin[heights.size() - 1] = heights.size();
            for (int i = heights.size() - 2; i >= 0; i--) {
                int right = i + 1;
                while (right <= heights.size() - 1 && heights[right] >= heights[i])
                    right = rightLessMin[right];
                rightLessMin[i] = right;
            }

            //calculate the max area for rectangle including the column
            int maxArea = 0;
            for (int i = 0; i <= heights.size() - 1; i++) {
                int area = (rightLessMin[i] - leftLessMin[i] - 1) * heights[i];
                maxArea = max(area, maxArea);
            }

            return maxArea;
        }
};

