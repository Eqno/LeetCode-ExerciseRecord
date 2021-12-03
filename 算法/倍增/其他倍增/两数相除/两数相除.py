'''
problem:
    给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
    返回被除数 dividend 除以除数 divisor 得到的商。
    整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
example:
    输入: dividend = 10, divisor = 3
    输出: 3
    解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
'''
class Solution:
    def parse(self, a, b):
        res = 1
        d = b
        while (d<<1)>=0 and (d<<1)<=a:
            res <<= 1
            d <<= 1
        if a >= b:
            res += self.parse(a-d, b)
        return res
    def divide(self, dividend: int, divisor: int) -> int:
        res = self.parse(abs(dividend), abs(divisor))-1
        res = -res if (dividend>>31)^(divisor>>31) else res
        return res-1 if res==(1<<31) else res
