//递归做法
class Solution {
public:
    int Fibonacci(int n) {
       if(n==0) return 0;
       else  if(n<=2) return 1;
       else return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
//保存中间项做法
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
