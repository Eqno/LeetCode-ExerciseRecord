# https://leetcode.cn/problems/flip-string-to-monotone-increasing/

class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        num0, num1, ans = s.count('0'), 0, 1000000
        ans = min(ans, num0 + num1)
        for i in s:
            if i == '0': num0 -= 1
            else: num1 += 1
            ans = min(ans, num0 + num1)
        return ans
        