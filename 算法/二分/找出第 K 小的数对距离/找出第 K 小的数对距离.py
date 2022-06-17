# https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums, n = sorted(nums), len(nums)
        L, R = 0, nums[n-1] - nums[0]
        while L <= R:
            M, C = (L + R) // 2, 0
            for i in range(n):
                l, r = 0, i
                while l <= r:
                    m = (l + r) // 2
                    if nums[i]-nums[m] > M: l = m + 1
                    else: r = m - 1
                C += i - l
            if C >= k: R = M - 1
            else: L = M + 1
        return L