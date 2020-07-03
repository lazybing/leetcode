/**
 * Calculate the sum of two integers a and b, but you are not allowed to
 * use the operate + and -.
 *
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 *
 * Example 2:
 * Input a = -2, b = 3
 * Output: 1
 */
class Solution {
    public:
        int getSum(int a, int b) {
            int ans = a ^ b;
            int c = a & b;

            while (c != 0) {
                c = (c & 0xFFFFFFFF) << 1;
                int ans_prim = ans ^ C;
                c = ans & c;
                ans = ans_prim;
            }

            return ans;
        }
};
