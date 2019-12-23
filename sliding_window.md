滑动窗口在 Leetcode 中占了很大的比例。

## 滑动窗口最大值

### 题目描述
> 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
>
> 返回滑动窗口中的最大值。
>
> 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3  
> 输出: [3,3,5,5,6,7]   
> 解释: 
> 
> |滑动窗口的位置         |     最大值  |
|---------------        |       -----  |
|[1  3  -1] -3  5  3  6  7  |    3  |
| 1 [3  -1  -3] 5  3  6  7  |    3  |
| 1  3 [-1  -3  5] 3  6  7  |   5  |
| 1  3  -1 [-3  5  3] 6  7  |  5  |
| 1  3  -1  -3 [5  3  6] 7  | 6  |
| 1  3  -1  -3  5 [3  6  7] |7  |
> 提示：可以假设 k 总是有效的，在输入数组不为空的情况下， 1<=k<=输入数组的大小。

### 方法一



```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        d = collections.deque()
        out = []
        
        for i, n in enumerate(nums):
            while d and nums[d[-1]] < n:
                d.pop()
            d += i,
            if d[0] == i - k:
                d.popleft()
            if i >= k - 1:
                out += nums[d[0]],

        return out
```



