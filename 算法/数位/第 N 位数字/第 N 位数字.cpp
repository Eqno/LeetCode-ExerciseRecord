/*
problem:
    给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位数字。
example:
    输入：n = 3
    输出：3
    输入：n = 11
    输出：0
    解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
*/
class Solution {
public:
    int findNthDigit(int n) {
        for (long long i=1, t=1; i<=10; i++)
        {
            if (n > i*9*t) n -= i*9*t, t *= 10;
            else
            {
                int num = t+n/i-(n%i==0), del = i-(n%i-1+i)%i-1;
                while (del--) num /= 10;
                return num % 10;
            }
        }
        return n;
    }
};