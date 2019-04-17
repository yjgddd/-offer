# 题目链接
[牛客网剑指offer-数值的整数次方](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
# 解题思路
## 思路一：调用pow函数
```
class Solution {
public:
    double Power(double base, int exponent) {
      return pow(base,exponent);
    }
};
```
## 思路二：递归和位运算
面试中显然不能写思路一那个解法。可以想到一种解法是O(n)的迭代，加上判断底数为0，指数为负数等特殊情况。

但是还有更高效的解法。假设求2^32,可以转换为求(2^16) * (2^16),2^16=(2^8) * (2^8),....也就是说，可以用如下公式：

当n为偶数时，a^n=(a^(n/2)) * (a^(n/2))

当n为奇数时，a^n=a^((n-1)/2) * a^((n-1)/2) * a

用右移运算符代替除以2，用位与运算符代替求余运算来判断一个数的奇偶性，提高效率。

# C++代码
```
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0) return 1;//判断底数为1
        if(exponent==1) return base;//指数为1返回base
        if(exponent==-1) return 1/base;//判断指数为负
        double result=Power(base,exponent>>1);//递归
        result*=result;
        if(exponent&0x1==1)//如果是奇数，多乘以一个base
            result*=base;
        return result;
    }
};
```
# 参考
【剑指offer-名企面试官精讲典型编程题(第二版)】

