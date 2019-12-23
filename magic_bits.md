# 神奇的比特

## 前言

现实生活中，人们处理的数字都是十进制的，但计算机中存储的都是二进制，因为了解二进制对于理解计算机很有帮助，同样的问题，换一个角度，可能就会有不一样的效果。

## 7.1 那些特立独行的数字

## 7.2 桶中摸黑白求

## 7.3 实现加法

### 题目描述
> Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.  
> 
> Example 1:  
> Input: a = 1, b = 2  
> Output: 3  
> 
> Example 2:  
> Input: a = -2, b = 3  
> Output: 1

### 方法一：

```
```

## 7.4 二进制 1 的个数

### 题目描述
> Write a function that takes an unsigned integer and return the number of '1' bits it has(also knownas the Hamming weight).
>
> Example 1:  
> Input: 00000000000000000000000000001011  
> Output: 3  
> Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.   
> Example 2:  
> Input: 00000000000000000000000010000000  
> Output: 1  
> Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.   
> Example 3:  
> Input: 11111111111111111111111111111101  
> Output: 31  
> Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.  

### 方法一

最直观的方法就是遍历 32 位数字的每一位，查看是否为 1， 如果是1，输入数字中含 1-bit 的个数加1。

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        retval = 0
        for i in range(32):
            if n & (1 << i):
                retval = retval + 1
                
        return retval
```
复杂度分析：  
时间复杂度：O(1)  
空间复杂度: O(1)  

### 方法二

上面的方法是对给定整数的每一位进行了计算，如果输入是` 0000000000000000000000000000001`,计算完第一位后，后面的所有操作不会增加1的个数，因为我们可以没检测完一位后，将该位置零，然后查看最后结果是否为零，如果为零，则中止计算即可。

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        retval = 0
        while n:
            retval = retval + 1
            n &= (n - 1)
                
        return retval
```
复杂度分析：  
时间复杂度：O(1)  
空间复杂度: O(1)  

### 方法三

利用python的内置函数完成，首先将输入的整数转换为字符串，然后计算字符串中 1 的个数。

```python
class Solution:
    def hammingWeight(self, n: int) -> int:
        """
        :type n: int
        :rtype: int
        """
        binary_str_n = bin(n)
        retval = binary_str_n.count('1')
        return retval
```
