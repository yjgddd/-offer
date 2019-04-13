# 题目链接

[牛客网剑指offer-调整数组顺序使奇数位于偶数前面](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

# 题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间
的相对位置不变。

# 解题思路
剑指offer书上并没有要求奇数和偶数的相对位置保持不变，因此可以用两个指针，一个初始化时指向数组第一个数字，只向后移动，一个初始化指向数组最后一个数字，只
向前移动，在两个指针相遇之前，如果第一个指针指向的数字是偶数，另一个指针指向的是奇数，那么交换两个位置上的数字，最后可以实现奇数在前，偶数在后。

但牛客网上的要求奇数和奇数，偶数和偶数之间的相对位置不变。一个比较简单的做法是用空间换时间，可以再开一个vector(C语言里面就是再开一个数组),遍历原来的数
组，先将所有的奇数插入新开的vetcor，再把所有偶数插入。最后再把vector复制到原来的数组中。
# C++代码
```
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector <int> temp;
        int i;
        for(i=0;i<array.size();i++)
            if(array[i]%2==1) temp.push_back(array[i]);
        for(i=0;i<array.size();i++)
            if(array[i]%2==0) temp.push_back(array[i]);
        for(i=0;i<array.size();i++)
            array[i]=temp[i];
    }
};
```
