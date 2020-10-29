"""
"You are climbing a stair case, It takes n steps to reach to the top.
"Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
"Example 1:
"   Input: 2
"   Output: 2
"   Explanation: There are two ways to climb to the top.
"   1. 1 step + 1 step
"   2. 2 steps
"Constraints:
    1 <= n <= 45
"""
def climbStairs(self, n):
    if n == 1:
        return 1
    a, b = 1, 2
    for i in xrange(2, n):
        tmp = b
        b = a + b
        a = tmp

    return b

