# https://leetcode.cn/problems/diagonal-traverse/

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        i, j, s, n, m, ans = 0, 0, 1, len(mat), len(mat[0]), []
        while True:
            if j >= m:
                i += 2
                j -= 1
                s = -s
            elif i >= n:
                i -= 1
                j += 2
                s = -s
            elif j <  0:
                j += 1
                s = -s
            elif i <  0:
                i += 1
                s = -s
            ans.append(mat[i][j])
            if i==n-1 and j==m-1:
                break
            i -= s
            j += s
        return ans
