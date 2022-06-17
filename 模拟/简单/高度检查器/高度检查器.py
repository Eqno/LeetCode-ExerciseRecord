# https://leetcode.cn/problems/height-checker/

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        exp, ans = sorted(copy.deepcopy(heights)), 0
        for i in range(len(exp)):
            if exp[i] != heights[i]:
                ans += 1
        return ans