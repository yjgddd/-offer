# 题目链接
[牛客网剑指offer-数组中重复的数字](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
# 解题思路
可以进行快排，那么很容易找出重复数字，不过时间复杂度O(nlogn)，也可以利用hash表，但是要多占用内存。

比较合适的解法是，由于数字所有的数字都在0-n-1的范围内，如果数组中没有重复的数字，那么i位置对应的数字就是i。从头遍历数组，如果numbers[i]==i，继续，
如果不是i，那么和其本来应该在位置上的数字比较，即比较numbers[i]和number[number[i]]，如果相等，那么numbers[i]即是一个重复的数字，因为它在位置i
和位置number[i]都出现了。如果不相等，交换numbers[i]和number[number[i]]位置上的数字，使得number[i]放在属于它的位置。不断比较、交换，直到找到重复数字。

# C++代码
```
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int i;
        if(numbers==NULL||length<=0) return false;
        for(i=0;i<length;i++)
        {
            if(numbers[i]<0||numbers[i]>length-1)
            return false;
        }
        for(i=0;i<length;i++)
        {
            while(numbers[i]!=i) 
            {
                if(numbers[i]==numbers[numbers[i]]) 
                {
                    * duplication=numbers[i];
                    return true;
                }
                else
                {
                    int temp;
                    temp=numbers[numbers[i]];
                    numbers[numbers[i]]=numbers[i];
                    numbers[i]=temp;
                }
            }
        }
        return false;
    }
};
```
