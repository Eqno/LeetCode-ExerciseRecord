// https://leetcode.cn/problems/diagonal-traverse/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i = 0, j = 0, s = 1, n = mat.size(), m = mat[0].size();
        while (1)
        {
                 if (j >= m) i += 2, j --, s = -s;
            else if (i >= n) i --, j += 2, s = -s;
            else if (i < 0) i ++, s = -s;
            else if (j < 0) j ++, s = -s;
            ans.emplace_back(mat[i][j]);
            if (i == n-1 && j == m-1) break;
            i -= s, j += s;
        }
        return ans;
    }
};