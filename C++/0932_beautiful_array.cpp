/**
 * For some fixed N, an array A is beautiful if it is a permutation of
 * the integers 1, 2, ..., N, such that:
 * 
 * For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j]
 *
 * Given N, return any beautiful array A.(It is guaranteed that one exists.)
 *
 * Example 1:
 * Input: 4
 * Output: [2, 1, 4, 3]
 *
 * Example 2:
 * Input: 5
 * Output: [3, 1, 2, 5, 4]
 *
 * Note: 1 <= N <= 1000
 */
class Solution {
    public:
        vector<int> beautifulArray(int N) {
            vector<int> res;
            if (N == 1) {
                res.push_back(1);
                return res;
            } else {
                vector<int> t = beautifulArray((N + 1) / 2);
                for (int i = 0; i < t.size(); i++) {
                    res.push_back(t[i] * 2 - 1);
                }

                vector<int> tt = beautifulArray(N / 2);
                for (int i = 0; i < tt.size(); i++) {
                    res.push_back(tt[i] * 2);
                }
                
                return res;
            }
        }
};
