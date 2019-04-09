# 题目链接
[牛客网剑指offer-斐波那契数列](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 
n<=39 
# 解题思路
斐波那契数列：0,1,1,2,3,5,8...
## 递归做法
递归的典型题目，从n=3开始是其前两项的和，因此n==0时候返回0，n==1以及n==2时候返回1，n>=2时候返回Fibonacci(n-1)+Fibonacci(n-2）
```
class Solution {
public:
    int Fibonacci(int n) {
       if(n==0) return 0;
       else  if(n<=2) return 1;
       else return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
```
## 保存中间项做法
递归的做法重复计算过多，效率低，因此要想办法避免重复计算。因为从n=2开始，该项等于前两项的和，因此可以保留前两项的值，比如根据f(0)和f(1)计算出f(2)，再根据f(1)和f(2)计算出f(3),依次类推求出第n项。时间复杂度是O(n)
```
class Solution {
public:
    int Fibonacci(int n) {
       if(n==0) return 0;
       if(n==1) return 1;
       int first=1,second=0,ans=0;
       for(int i=2;i<=n;i++)
       {
           ans=first+second;
           second=first;
           first=ans;
       }
       return ans;
    }
};
```
## 矩阵快速幂做法

待更...
