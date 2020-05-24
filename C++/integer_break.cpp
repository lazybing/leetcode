/*
 * Given a positive integer n, break it into the sum of at least two positive integers
 * and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 * Example 1:
 * Input  : 2
 * Output : 1
 * Explanation: 2 = 1 + 1, 1 x 1 = 1.
 *
 * Example 2:
 * Input  : 10
 * Output : 36
 * Explanaton: 10 = 3 + 3 + 4, 3 x 3 x 4 = 36.
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 */
class Solution{
    public:
        int integerBreak(int n) {
           int ret = 0; 

           if (n == 2) return 1;
           if (n == 3) return 2;

           for (int i = 1; i < n; i++) 
                ret = max(ret, max(integerBreak(n - i) * i, i * (n - i)));

           return ret;
        }

        int integerBreak2(int n) {
            if (n <= 2)
                return 1;

            vector<int> maxArr(n + 1, 0);

            maxArr[1] = 0;
            maxArr[2] = 1;

            for (int i = 3; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    maxArr[i] = max(maxArr[i], max(j * (i - j), j * maxArr[i - j]));
                }
            }

            return maxArr[n];
        }

        //Math Method
        int integerBreak3(int n) {
            int p = n % 3, q = n / 3, r = p + (2 * p + 1) % 5;
            return n <= 3 ? n - 1 : (int)(pow(3, q - (p & 1)) * r);
        }
};



