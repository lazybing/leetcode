# 第十一章 滑动窗口

滑动窗口在 Leetcode 中占了很大的比例。

## 11.1 滑动窗口最大值

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

### 解法一：暴力法

遍历所有的滑动窗口，找到每个窗口的最大值。一共有`N - k + 1`个滑动窗口，每个有`k`个元素，表现较差。

```python
class Solution:
    def maxSlidingWindow(self, nums:List[int], k:int)->List[int]:
        length = len(nums)
        if length * k == 0:
            return []
            
        output = []
        for i in range(length - k + 1):
            max_val = -sys.maxsize - 1
            for j in range(i, i + k):
                max_val = max(max_val, nums[j])
                
            output.append(max_val)
            
        return output
```

复杂度分析：
* 时间复杂度: O(N*k)。其中`N`为数组中元素个数。
* 空间复杂度: O(N - k + 1)，用于输出数组。



### 解法二:滑动窗口法

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
                out.append(nums[d[0]])

        return out
```

### 解法三

```

```

## 11.2 最小覆盖子串

### 题目描述

> 给一个字符串S，一个字符串T，请在字符串S里面找到：包含T所有字母的最小子串。
>
> 示例：  
> 输入: S = "ADOBECODEBANC", T = "ABC"  
> 输出: "BANC"  
> 
> 说明:
> 
> * 如果S中不存在这样的子串，则返回空字符串""
> * 如果S中存在这样的子串，我们保证它是唯一的答案。

### 解法一：滑动窗口法

具体步骤：

1. 初始化窗口的左右两端,使得`left`和`right`都指向S的第一个元素。
2. 将`right`指针右移，使得窗口中包含T的全部字符。
3. 若2中能找到此窗口，右移`left`指针，使得窗口缩小。
4. 若窗口不包含T的全部字符，则跳转至2。

```python
def minWindow(self, s, t):
    if not t or not s:
        return ""
        
    
```

#### 复杂度分析：
* 时间复杂度: O(|S| + |T|), 其中|S| 和 |T| 代表字符串 S 和 T 的长度。在最坏的情况下，可能会对S中的每个元素遍历两遍，左指针和右指针各一遍。
* 空间复杂度: O(|S| + |T|)。当窗口大小等于 |S| 时为S。当|T|包括全部唯一字符时为T。

### 解法二：优化滑动窗口
```python
```

#### 复杂度分析：
* 时间复杂度：O(|S| + |T|),其中 |S| 和 |T| 分别代表字符串 S 和 T的长度。
* 空间复杂度: O(|S| + |T|)。

## 11.3 替换后的最长重复字符

### 题目描述

> 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上 的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。
> 
> **注意**：  
> 字符串长度和k不会超过10^4.
>
> **示例1：**  
> 输入: S="ABAB"，k = 2
> 输出：4
>
> **解释:** 用两个'A'替换为两个'B'，反之亦然。
>
> **示例2：**
>
> 输入：S="AABABBA"，k = 1  
> 输出: 4  
> 解释: 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

### 解法一：

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = low = high = 0
        counts = collections.Counter()
        
        for high in range(1, len(s) + 1):
            counts[s[high - 1]] += 1
            max_char_n = counts.most_common(1)[0][1]
            
            if high - low - max_char_n > k:
                counts[s[low]] -= 1
                low += 1
        
        return high -low
```

### 解法二：
```
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxf = res = 0
        count = collections.Counter()
        for i in range(len(s)):
            count[s[i]] += 1
            maxf = max(maxf, count[s[i]])
            
            if res - maxf < k:
                res += 1
            else:
                count[s[i - res]] -= 1
                
        return res
```

## 11.4 字符串的排列

### 题目描述
> 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
> 
> 换句话说，第一个字符串的排列之一是第二个字符串的子串。
> 
> **示例1:**  
> 输入：s1 = "ab"， s2 = "eidbaooo"  
> 输出：True  
> 解释：s2 包含 s1 的排列之一("ba")  
>
> **示例2:**
> 输入：s1="ab" s2="eidboaoo"  
> 输出：False
>
> **注意**  
> 1. 输入的字符串只包含小写字母。
> 2. 两个字符串的长度都在[1, 10000]之间。

#### 解法一：暴力法

#### 解法二：滑动窗口



