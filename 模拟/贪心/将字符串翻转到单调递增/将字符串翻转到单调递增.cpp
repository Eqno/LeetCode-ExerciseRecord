// https://leetcode.cn/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num0 = 0, num1 = 0, ans = 1e6;
        for (char c : s) if (c == '0') num0 ++;
        for (char c : s)
        {
            ans = min(ans, num0 + num1);
            if (c == '1') num1 ++;
            else num0 --;
        }
        ans = min(ans, num0 + num1);
        return ans;
    }
};