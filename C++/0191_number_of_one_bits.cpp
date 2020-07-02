/**
 * Write a function that takes an unsigned integer and 
 * return the number of '1' bits it has(also known as the Hamming weight)
 *
 * Example 1:
 * Input: 0001011
 * Output: 3
 * Explanation: The input binary string 0001011 has a total of three '1' bits.
 *
 * Note:
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, the input will be given as signed integer type and should not
 * affect your implementation, as the internal binary representation of the 
 * integer is the same whether it is signed or unsgiend.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 3 above the input represents the signed integer -3.
 */
class Solution {
    public:
        int hammingWeight(uint32_t) {
            int num = 0;
            for (int i = 0; i < 32; i++) {
                if (n & (1 << i))
                    num++;
            }

            return num;
        }
};

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int ret = 0;

            while (n) {
                ret = ret + 1;
                n &= (n - 1);
            }

            return ret;
        }
};

