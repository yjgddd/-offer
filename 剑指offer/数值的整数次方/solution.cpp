class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0) return 1;
        if(exponent==1) return base;
        if(exponent==-1) return 1/base;
        double result=Power(base,exponent>>1);//递归
        result*=result;
        if(exponent&0x1==1)//如果是奇数，多乘以一个base
            result*=base;
        return result;
    }
};
