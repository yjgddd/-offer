# 题目链接
[牛客网剑指offer-不用加减乘除做加法](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
# 解题思路
step1: num1和num2按位抑或，只有两个数的对应二进制位只有一个是1，才会产生1，即可以求得不产生进位的和

step2: num1和num2按位与，可以得到两个数的二进制位都是1，必然产生进位，按为与的结果左移一位，就是需要的进位,不为0则需要加在返回值上

step3: 如果仍然有进位，即(num1&num2)<<1不为0，那么重复step1和step2

Tips: <<(位移操作符)比&(位与操作符）优先级高，要带上括号
# C++代码
```
//将num1作为最终的返回值，即两个数的和，num2作为进位检查标志
class Solution {
public:
    int Add(int num1, int num2)
    {
       int temp;
       while(num2)
       {
           temp=num1^num2;//temp是两个数无进位和
           num2=(num1&num2)<<1;//num2是进位,如果num2不为0，那么还需要加上进位,即再继续进行抑或操作
           num1=temp;//循环结束后num1是最终结果
       }
        return num1;
    }
};
```
