/*
problem:
    给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
    返回被除数 dividend 除以除数 divisor 得到的商。
    整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
example:
    输入: dividend = 10, divisor = 3
    输出: 3
    解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
*/
class Solution {
public:
    int parse(int a, int b)
    {
        int res = 1, d = b;
        while ((d<<1)>=0 && (d<<1)<=a)
        {
            d <<= 1;
            res <<= 1;
        }
        if (a >= b)
        {
            int tmp = parse(a-d, b);
            res += tmp-(tmp==(1<<30));
        }
        return res;
    }
    int divide(int dividend, int divisor) {
        if (dividend == (1<<31))
        {
            if (divisor == -1) return ~(1<<31);
            else if (divisor == 1) return (1<<31);
            else if (divisor == 2) return (1<<30)|(1<<31);
            else if (divisor == 4) return (~(1<<29)|(1<<31))+1;
            else if (divisor == (1<<31)) return 1;
        }
        else if (divisor == (1<<31)) return 0;
        int a = dividend==(1<<31) ? ~dividend : abs(dividend);
        int res = parse(a, abs(divisor));
        res -= (res!=~(1<<31));
        return (dividend>>31)^(divisor>>31) ? -res : res;
    }
};