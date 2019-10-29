前言
===

LeetCode 中有许多与字符串、数组、链表以及滑动窗口相关的题目，都用到了一种称为双指针`two pointer`的方法，顾名思义，双指针是指有两个游标指针指向不同的位置，注意此处的指针与C/C++语言中的指针并不完全相同，可以理解为指向不同位置的两个游标。

双指针有两种类型，一种是起始位置位于首尾、移动步长相同的“首尾双指针”，一种是起始位置相同、移动步长不同的“快慢双指针”。双指针是针对特定问题而提出的一种算法思想。

示例
===

### 双指针与链表

>LeetCode141 Linked List Cycle.  
>
>Given a linked list, determine if it has a cycle in it.
>
>To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

查看链表是否有环。
![](https://raw.githubusercontent.com/lazybing/leetcode/master/img/cycle.png)

---

方法一：哈希法。遍历整个链表，查看是否存在某个节点遍历过两次，如果存在这样的节点，就证明有环存在，否则，没有环。因为要查看节点出现的次数，所以很容易想到使用 Hash Table 存储之前遍历过的节点。

![](https://raw.githubusercontent.com/lazybing/leetcode/master/img/hash_table.png)

如上图所示，首先创建一个空的哈希表，依次往哈希表中插入链表的节点 3-->2-->0-->4,如果链表有环，接下来再继续查看哈希表中是否有下一个节点 `2`,如果有此节点，则证明有环；否则，无环。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> seenNode;
        while (head) {
            if (seenNode.find(head) != seenNode.end())
                return true;
            seenNode.insert(head);
            head = head->next;
        }
        return false;  
    }
};
```

复杂度分析：

* 时间复杂度：O(n)。遍历链表中的每个节点，添加节点到哈希表所用时间为O(1)。
* 空间复杂度: O(n)。所用空间取决于添加到哈希表中的节点个数，最多为 n。

---

方法二：双指针法。类似于两个不同速度的人跑步，如果是围着操场跑圈，快的总能多跑一圈后追上慢的；如果是直线跑，除了起点外，两人就永远不会在相遇了。同样的道理，从链表的起始点开始给到两个快速、慢速指针，如果有环，快速指针总能追上慢速指针，如果没有环，快速指针提前到链表尾部，结束。

![](https://raw.githubusercontent.com/lazybing/leetcode/master/img/two_pointer.png)

如上图所示，将快慢指针同时初始化为第一个节点，如图1所示。快指针每次移动步长为2，慢指针每次移动步长为1.慢指针到达节点2时，进入环内，此时快指针指向节点0.如图2所示。继续一定，快指针第二次指向2节点，慢指针指向0节点，如图3所示。最后，快指针慢指针在节点4处再次相遇，证明有环，如图4所示。如果无环，快指针会提前到达链表终点。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode *p_slow = head;
        ListNode *p_fast = head;
        
        while(p_slow != NULL && p_fast->next != NULL){
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
            
            if (p_slow == p_fast)
                return true;
        }
        
        return false;
    }
};
```

复杂度分析：

* 时间复杂度：O(n)。n 为链表中节点的个数。为分析时间复杂度，考虑两种情况：  
    1. 链表无环： 快速指针到达链表终点，结束。执行时间与链表长度相关，即O(n).  
    2. 链表有环：将慢速指针的整个路径分为两部分，环内部分和环外部分。① 当慢速指针在环外移动了 N 步以后，快速指针在环内移动了 N 步。② 此时快慢指针都在环内，假设环的长度为 K，环内快速指针追上慢指针，最糟糕的情况为 O(K)，整个过程最糟糕情况为O(N + K),即 O(N)。
* 空间复杂度：O(1)。因为使用了两个节点，所以空间复杂度为O(1)。

----

### 双指针与数组


> LeetCode11 Container With Most Water  
>
> Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
> 
> Note: You may not slant the container and n is at least 2.

![](https://raw.githubusercontent.com/lazybing/leetcode/master/img/container_with_most_water.png)

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

最大储水能力。

方法一：暴力法。遍历所有可能储水情况，找到其中的最大值即可。但该方法会计算超时。

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int area = 0;
        for (int i = 0; i < height.size() - 1; i++)
            for (int j = i + 1; j < height.size(); j++) {
                area = (j - i) * min(height[i], height[j]);
                if (area > res)
                    res = area;
            }
        return res;
    }
};
```

复杂度分析：
* 时间复杂度：O(n^2)。对每一对儿进行计算，总计算结果一共 n(n - 1) / 2.
* 空间复杂度：O(1)。只需要额外的一个变量存放最大面积即可。

方法二：双指针法。如下图所示，任意两个数组元素(a[i + n] 和 a[i - j ])的最大储水能力为  

`area = max(a[i + n], a[i - j]) * (i + n - (i - j))`  

![](https://raw.githubusercontent.com/lazybing/leetcode/master/img/leetcode11_1.png)


选取数组的开始和末尾元素作为首尾双指针的起始位置，计算两个指针可容纳的储水面积，之后移动数值较小的指针向中间靠拢，重新计算两个指针可容纳的储水面积并与之前的最大面积做比较，以此类推，直至两个指针相遇位置，即可得最大面积。  

下面给出这种计算和合理性说明。选取第一个和最后一个元素时，量元素的最大储水能力为 `area = max(a[0], a[size]) * (size)`.假设a[0]是较小者，则a[0]与其他任一元素的储水能力不可能超过 area，因为`max(a[0], a[i]) <= a[0]`，而`i < size`，所以`max(a[0], a[i]) * size <  max(a[0], a[size]) * (size)`.


![](https://raw.githubusercontent.com/lazybing/leetcode/master/img/leetcode11_2.png)

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int area = 0;
        int left = 0, right = height.size() - 1;
        
        while(left < right) {
            area = (right - left) * min(height[right], height[left]);
            res  = max(res, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return res;
    }
};
```
复杂度分析：  

* 时间复杂度：O(n)。遍历一次 vector 中的所有元素。
* 空间复杂度：O(1)。使用恒定空间。

### 双指针与滑动窗口

> LeetCode3 Longest Substring Without Repeating Characters
>
> Given a string, find the length of the longest substring without repeating characters.
> 
Test Case:
 
 | Input | Output | Explanation  |
 | :---: | :----: | :---------:  |
 |"abcabcbb"  | 3 | substr:"abc", len is 3  |
 | "bbbbb"    | 1 | substr:"b", len is 1  |
 | "pwwkew"   | 3 | substr:"wke", len is 3  |



方法一：暴力法。

```
class Solution1 {
    private:
        bool allUnique(string s){
            unordered_map<char, int> mapping;
            for (int i = 0; i < s.size(); i++) {
                if (mapping.find(s[i]) == mapping.end())
                    mapping.insert({s[i], 1});
                else
                    return false;
            }
            return true;
        }
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0;
            for (int i = 0; i < s.size(); i++)
                for (int j = i; j < s.size(); j++)
                    if (allUnique(s.substr(i, j - i + 1)))
                        res = max(res, j - i + 1);
                    else
                        break;

            return res;
        }
};
```
复杂度分析：
时间复杂度：O(n^3)。
方法二：

```
class Solution2 {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            unordered_set<char> setting;

            for (left = 0; left < s.size(); left++) {
                right = left;
                while (right < s.size()) {
                    if (setting.find(s[right]) != setting.end()) { //has the char
                        break;
                    } else { // donnot has the char
                        setting.insert(s[right]);
                        res = max(res, right - left + 1);
                        right++;
                    }
                }
                setting.clear();
            }

            return res;
        }
};
```

方法三：

```
class Solution3{
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            unordered_set<char> setting;

            while (right < s.size()) {
                if (setting.find(s[right]) != setting.end()) {
                    while(left < right) {
                        if (s[left] == s[right]) {
                            setting.erase(s[left]);
                            left++;
                            break;
                        } else {
                            setting.erase(s[left]);
                            left++;
                        }
                    }
                }
                setting.insert(s[right]);
                res = max(res, right - left + 1);
                right++;
            }
            return res;
        }
};
```

方法四：

```
class Solution4 {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            unordered_map<char, int> mapping;
            while (right < s.size() && left + res < s.size()) {
                if (mapping.find(s[right]) != mapping.end()) {
                    left = max(left, mapping[s[right]] + 1);
                }
                mapping[s[right]] = right;
                res = max(res, right - left + 1);
                right++;
            }

            return res;
        }
}
```

方法五:

```
class Solution5 {
    public:
        int lengthOfLongestSubstring(string s) {
            int res = 0, left = 0, right = 0;
            int charset[256] = {-1};

            while (right < s.size() && left + res < s.size()) {
                left = max(left, charset[s[right]]);
                res  = max(res, right - left + 1);
                charset[s[right]] = right + 1;
                right++;
            }

            return res;
        }
};
```
小结：

1. 滑动窗口的边界条件可以设置为(right < end_of_string && left + window_size < end_of_string)。
2. 注意 unordered_set 和 unordered_map 的使用方法。
3. 注意 mapping.insert({key, val}) 和 mpaping[key] = val 的区别。
4. 针对字符串相关问题，注意使用三个字符表格，char[26] 用于 'a'-'z' 或 'A'-'Z'；char[128] 用于 ASCII 码；char[256] 用于扩展的 ASCII 码。

总结
===

对于可以使用双指针的问题，多多考虑使用的指针类型，是从一边开始的快慢指针，还是从两边开始的首尾指针。针对快慢指针，用于 sliding window 问题时，还可以考虑通过指针控制窗口的大小来优化算法。后续会再提到。
