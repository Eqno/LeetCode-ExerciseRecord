'''
problem:
    给你一个数组 seats 表示一排座位，其中 seats[i] = 1 代表有人坐在第 i 个座位上，seats[i] = 0 代表座位 i 上是空的（下标从 0 开始）。
    至少有一个空座位，且至少有一人已经坐在座位上。
    亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
    返回他到离他最近的人的最大距离。
example:
    输入：seats = [1,0,0,0,1,0,1]
    输出：2
    解释：
    如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
    如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
    因此，他到离他最近的人的最大距离是 2 。 
'''
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        last = 0
        ans = 0
        start = 1
        for i, j in enumerate(seats):
            if j:
                if start:
                    ans = max(ans, i-last)
                    start = 0
                else:
                    ans = max(ans, (i-last)//2)
                last = i
        if not seats[len(seats)-1]:
            ans = max(ans, len(seats)-1-last)
        return ans