'''
problem:
    实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。
example:
    输入：x = 2.00000, n = 10
    输出：1024.00000
'''
class Solution:
    def ksm(self, x, n):
        res = x
        m = 1
        while (m<<1) <= n:
            res *= res
            m <<= 1
        if n-m > 0:
            res *= self.ksm(x, n-m)
        return res
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        return self.ksm(x, n) if n>0 else 1/self.ksm(x, -n)