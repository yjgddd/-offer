//递归
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1) return 1;
        else if(number==2) return 2;
        else return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
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
