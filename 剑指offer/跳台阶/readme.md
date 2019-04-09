# 题目链接
[牛客网剑指offer-跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
# 解题思路
典型递归题目。只有1级台阶时只有一种跳法：1 级，只有两级台阶时，两种跳法： 1级，1级和一次2级。当台阶总数大于2时候，如果先1级，后面跳法是
jumpFloor(number-1)种，如果先跳2级，后面跳法是jumpFloor(number-2)种，因此一共是jumpFloor(number-1)+jumpFloor(number-2)种。思考到这里，就可以看出，这又是斐波那契数列。同样由于递归有多次重复计算，迭代（保存中间项）的做法要比递归做法更高效。
# C++代码
```
//递归
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1) return 1;
        else if(number==2) return 2;
        else return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
```
```
//迭代
class Solution {
public:
    int jumpFloor(int number) {
       if(number==0) return 0;
       if(number==1) return 1;
       if(number==2) return 2;
       int first=1,second=2,ans=0;
       for(int i=3;i<=number;i++)
       {
           ans=first+second;
           first=second;
           second=ans;
       }
       return ans;
    };
};
```

