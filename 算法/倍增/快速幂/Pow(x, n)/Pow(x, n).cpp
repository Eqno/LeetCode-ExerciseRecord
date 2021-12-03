/*
problem:
    实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
example:
    输入：x = 2.00000, n = 10
    输出：1024.00000
*/
class Solution {
public:
    double ksm(double x, long long n)
    {
        double res = x;
        long long m = 1;
        while ((m<<1) <= n)
        {
            res *= res;
            m <<= 1;
        }
        if (n-m > 0) res *= ksm(x, n-m);
        return res;
    }
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double res;
        if (n == (1<<31)) res = ksm(x, abs(n+1))*x;
        else res = ksm(x, abs(n));
        if (n < 0) res = 1./res;
        return res;
    }
};