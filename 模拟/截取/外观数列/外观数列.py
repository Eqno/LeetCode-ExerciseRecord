# https://leetcode.cn/problems/count-and-say/

class Solution:
    def getNext(self, s):
        l, c, r = '', 1, ''
        for i in s:
            if i != l:
                if l != '':
                    r += str(c) + l
                l = i
                c = 1
            else:
                c += 1
        r += str(c) + l
        return r

    def countAndSay(self, n: int) -> str:
        s = '1'
        while n > 1:
            s = self.getNext(s)
            n -= 1
        return s