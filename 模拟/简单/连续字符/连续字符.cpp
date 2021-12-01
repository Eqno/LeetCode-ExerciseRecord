/*
problem:
    给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
    请你返回字符串的能量。
example:
    输入：s = "leetcode"
    输出：2
    解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
*/
class Solution {
public:
    int maxPower(string s) {
        int last = 0, cot = 1, ans = 0;
        for (auto i: s) { if (i == last) cot ++; else cot = 1; ans = max(ans, cot), last = i; }
        return ans;
    }
};