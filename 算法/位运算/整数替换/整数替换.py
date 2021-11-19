'''
problem:
    给定一个正整数 n ，你可以做如下操作：
    如果 n 是偶数，则用 n / 2替换 n 。
    如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
    n 变为 1 所需的最小替换次数是多少？
example:
    输入：n = 8
    输出：3
    解释：8 -> 4 -> 2 -> 1
'''
class Solution:
    def integerReplacement(self, n: int) -> int:
        ans = 0
        while n:
            ans += 1 + (n&1)
            n = (n + (n!=3 and (n&1) and (n>>1&1))) >> 1
        return ans - 2