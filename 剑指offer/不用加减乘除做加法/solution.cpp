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
