# 题目链接
[牛客网剑指offer-旋转数组的最小数字](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
# 解题思路
## 思路一
只要下一个数字比当前的小，那么它一定是未旋转时候的第一个数字，也即最小元素
C++代码
```
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       int i;
       for(i=0;i<rotateArray.size()-1;i++)
       if(rotateArray[i]>rotateArray[i+1]) return rotateArray[i+1];
       return 0;
    }
};
```
## 思路二
数组是局部有序的，因此可以用二分法来提高查找的效率
