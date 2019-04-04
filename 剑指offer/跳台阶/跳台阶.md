# 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
# 解题思路
典型递归题目。只有1级台阶时只有一种跳法：1 级，只有两级台阶时，两种跳法： 1级，1级和一次2级。当台阶总数大于2时候，如果最后一步跳1级，前面跳法是
jumpFloor(number-1)种，如果最后一步跳2级，前面跳法是jumpFloor(number-2)种，因此一共是jumpFloor(number-1)+jumpFloor(number-2)种。
# C++代码
```
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1) return 1;
        else if(number==2) return 2;
        else return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
```
