# 题目链接
[牛客网剑指offer-变态跳台阶](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
# 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
# 解题思路
n级台阶第一次可以一次跳1级、2级、3级...n级，根据数学归纳法，

jumpFloorII(1)=1

jumpFloorII(n-1)=f(n-2)+f(n-3)+...f(1)

jumpFloorII(n)=jumpFloorII(n-1)+jumpFloorII(n-2)+jumpFloorII(n-3)+...f(1)=jumpFloorII(n-1)+jumpFloorII(n-1)=2*jumpFloorII(n-1)

因此jumpFloorII(n)=2^(n-1),可以用位移实现。

# C++代码
```
class Solution {
public:
    int jumpFloorII(int number) {
       int ans=1;
       return ans<<(number-1);
    }
};
```
