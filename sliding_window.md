# 第十一章 滑动窗口

滑动窗口在 Leetcode 中占了很大的比例。常用于解决数组、字符串的子元素问题，它可以将嵌套的循环问题，转换为单循环问题，降低时间复杂度。

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

遍历数组包含的所有可能的窗口。计算每个窗口中所有元素的最大值。一共有 `N - k + 1` 个滑动窗口，每个窗口有 `k` 个元素，该算法表现较差。

```python
class Solution:
    def maxSlidingWindow(self, nums:List[int], k:int)->List[int]:
        length = len(nums)
        if length * k == 0:
            return []
            
        output = []
        # 遍历所有可能的窗口
        for i in range(length - k + 1):
            max_val = -sys.maxsize - 1
            # 找到一个窗口中的最大值
            for j in range(i, i + k):
                max_val = max(max_val, nums[j])
                
            # 将最大值放到数组列表里
            output.append(max_val)
            
        return output
```

复杂度分析：
* 时间复杂度: O(N*k)。其中`N`为数组中元素个数。
* 空间复杂度: O(N - k + 1)，用于输出数组。



### 解法二:滑动窗口法

暴力法每次都比较滑动窗口中所有元素的大小，当`k`较大时，会有很多重复操作。如果能有种方法在滑动窗口每移动一个元素，将窗口外的元素删除、将窗口内所有比新加入元素小的元素删除，以后每次加入新的元素就能省掉很多重复操作。

为此，我们引入双向队列。双向队列允许头尾两端都能在O(1)的时间内进行数据的查看、添加和删除。用双向队列存放元素索引，而不是元素本身。

算法如下：

1. 每次添加新的元素，移除滑动窗口外的元素索引。  
2. 移除比当前新元素小的所有元素。
3. 将当前元素添加到双向队列中。
4. 将双向队列中的[0]元素添加到输出中。
5. 遍历完所有元素后，返回输出数组。

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        d = collections.deque()
        out = []
        
        for i, n in enumerate(nums):
            # 移除所有比当前元素小的元素
            while d and nums[d[-1]] < n:
                d.pop()
            d += i,
            if d[0] == i - k:
                d.popleft()
            if i >= k - 1:
                out.append(nums[d[0]])

        return out
```

#### 复杂度分析：
* 时间复杂度：O(N)，每个元素被处理两次-其索引被添加到双向队列中和从双向队列删除。
* 空间复杂度：O(N)，输出数组使用了O(N - k + 1)空间，双向队列使用了O(k)。

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

### 解法一：暴力法

针对字符串S中的所有子字符串，检测是否包含字符串T的所有字符。该方法简单直接，但效率低。此处略去。

### 解法二：滑动窗口法

移动 `right` 指针不断扩大窗口，当窗口包含全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。

具体步骤：

1. 初始化窗口的左右两端,使得`left`和`right`都指向S的第一个元素。
2. 将`right`指针右移，使得窗口中包含T的全部字符。
3. 若2中能找到此窗口，右移`left`指针，使得窗口缩小。
4. 若窗口不包含T的全部字符，则跳转至2。

```python
class Solution:
    def minWindow(self, s:str, t:str)->str:
        if not t or not s:
            return ""
            
        dict_t = Counter(t)
        
        required = len(dict_t)
        
        #初始化滑动窗口
        left, right = 0, 0
        
        formed = 0
        
        window_counts = {}
        
        ans = float("inf"), None, None
        
        while right < len(s):
            character = s[right]
            window_counts[character] = window_counts.get(character, 0) + 1
            
            if character in dict_t and window_counts[character] == dict_t[character]:
                formed += 1
                
            while left <= right and formed == required:
                character = s[left]
                
                if right - left + 1 < ans[0]:
                    ans = (right - left + 1, left, right)
                    
                window_counts[character] -= 1
                if character in dict_t and window_counts[character] < dict_t[character]:
                    formed -= 1
                    
                left += 1
            right += 1
                
        if ans[0] == float("inf"):
            return ""
        else:
            return s[ans[1]: ans[2] + 1]
        
```

#### 复杂度分析：
* 时间复杂度：O(|S| + |T|), 其中|S| 和 |T| 代表字符串 S 和 T 的长度。在最坏的情况下，可能会对S中的每个元素遍历两遍，左指针和右指针各一遍。
* 空间复杂度：O(|S| + |T|)。当窗口大小等于 |S| 时为S。当|T|包括全部唯一字符时为T。

### 解法三：优化滑动窗口

从S中去除所有在T中不存在的元素后，得到filtered_S字符串，它包含S中的全部字符以及它们在S的下标。

比如`S="ABCDDDDDDEEAFFBC"`和 `T="ABC"`，则

`filtered_S = [(0, 'A'), (1, 'B'), (2, 'C'), (11, 'A'), (14, 'B'), (15, 'C')]`

此处的(0, 'A')表示字符'A'在字符串S的下表为0.接下来可以在更短的filtered_S中使用滑动窗口法。

当|filtered_S| <<< |S|时，优化效果显著。

```python
class Solution:
    def minWindow(self, s, t):
        if not t or not s:
            return ""
            
        dict_t = Counter(t)
        
        required = len(dict_t)
        
        for i, char in enumerate(s):
            if char in dict_t:
                filtered_s.append((i, char))
                
        left, right = 0, 0
        formed = 0
        window_counts = {}
        
        ans = float("inf"), None, None
        
        while right < len(filtered_s):
            character = filtered_s[r][1]
            window_counts[character] = window_counts.get(character, 0) + 1
            
            if window_counts[character] == dict_t[character]:
                formed += 1
                
            while left <= right and formed == required:
                character = filtered_s[l][1]
                
                end   = filtered_s[right][0]
                start = filtered_s[left][0]
                if end - start + 1 < ans[0]:
                    ans = (end - start + 1, start, end)
                    
                window_counts[character] -= 1
                if window_counts[character] < dict_t[character]:
                    formed -= 1
                left += 1
                
            right += 1
            
        if ans[0] == float("inf"):
            return ""
        else:
            return s[ans[1]:ans[2] + 1]
```

#### 复杂度分析：
* 时间复杂度：O(|S| + |T|),其中 |S| 和 |T| 分别代表字符串 S 和 T的长度。
* 空间复杂度：O(|S| + |T|)。

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

使用滑动窗口：



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

### 解法二：滑动窗口法

当滑动窗口大小达到给定的最大值k后，窗口一直前进；当窗口内记载的出现次数最大字符大于上一次的出现最大次数字符时，窗口长度增加；否则，窗口保持原来长度前进一个单位。

```python
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

#### 复杂度分析：  
* 时间复杂度：O(N)。
* 空间复杂度：O(1)。

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

最简单的方法生成所有字符串的组合，然后检测这些生成的字符串是否是长字符串的子串。

```python
class Solution:
    def perm(self, s=''):
        if len(s) <= 1:
            return [s]
        
        s1 = []
        for i in range(len(s)):
            for j in self.perm(s[0:i] + s[i + 1:]):
                s1.append(s[i] + j)
                
        return s1
    
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if (len(s1) > len(s2)):
            return False
        
        s1_perm = list(set(self.perm(s1)))
        for i in s1_perm:
            idx = s2.find(i)
            if idx != -1:
                return True
            
        return False
```

#### 复杂度分析：

* 时间复杂度:O(n!)。
* 空间复杂度:O(n^2)。

#### 解法二：滑动窗口

使用和 S1 等长的滑动窗口判断 S2 在这个窗口内的字符出现个数和 S1 的字符出现个数是否相等。

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if (len(s1) > len(s2)):
            return False
        
        c = collections.Counter(s1)
        
        len1  = len(s1)
        left, right = 0, len1 - 1
        
        s = collections.Counter(s2[left:right])
        
        while right < len(s2):
            s[s2[right]] += 1
            if s == c:
                return True
            
            s[s2[left]] -= 1
            if (s[s2[left]] == 0):
                del s[s2[left]]
                
            left  += 1
            right += 1
            
        return False
```

#### 解法三：滑动窗口

```python
class Solution:
    def match(self, s1, s2):
        for i in range(26):
            if s1[i] != s2[i]:
                return False
        return True
            
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if (len(s1) > len(s2)):
            return False
        
        list1 = [0 for i in range(26)]
        list2 = [0 for i in range(26)]
        
        for i in range(len(s1)):
            list1[ord(s1[i]) - ord('a')] += 1
            list2[ord(s2[i]) - ord('a')] += 1
            
        for i in range(len(s2) - len(s1)):
            if self.match(list1, list2):
                return True
            list2[ord(s2[i + len(s1)]) - ord('a')] += 1
            list2[ord(s2[i]) - ord('a')] -= 1

        return self.match(list1, list2)
```

#### 解法四：优化滑动窗口

```python
class Solution:
       
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if (len(s1) > len(s2)):
            return False
        
        list1 = [0 for i in range(26)]
        list2 = [0 for i in range(26)]
        
        for i in range(len(s1)):
            list1[ord(s1[i]) - ord('a')] += 1
            list2[ord(s2[i]) - ord('a')] += 1
            
        count = 0
        for i in range(26):
            if list1[i] == list2[i]:
                count += 1
                
        for i in range(len(s2) - len(s1)):
            r = ord(s2[i + len(s1)]) - ord('a')
            l = ord(s2[i]) - ord('a')
            if count == 26:
                return True
            
            list2[r] += 1
            if list2[r] == list1[r]:
                count += 1
            elif list2[r] == list1[r] + 1:
                count -= 1
                
            list2[l] -= 1
            if list2[l] == list1[l]:
                count += 1
            elif list2[l] == list1[l] - 1:
                count -= 1
                
        return count == 26
```

#### 复杂度分析

* 时间复杂度:O(len1 + (len2 - len1),其中len1是s1的长度,len2是s2的长度。
* 空间复杂度:O(1)。



