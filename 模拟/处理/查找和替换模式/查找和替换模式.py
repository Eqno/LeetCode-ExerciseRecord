# https://leetcode.cn/problems/find-and-replace-pattern/

class Solution:
    def process(self, s):
        cot, num, res = 0, {}, [i for i in s]
        for i in range(len(res)):
            if res[i] not in num.keys():
                num[res[i]] = cot
                cot += 1
            res[i] = num[res[i]]
        s = ''
        for i in res:
            s += str(i)
        return s
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        return list(filter(lambda s: self.process(s)==self.process(pattern), words))