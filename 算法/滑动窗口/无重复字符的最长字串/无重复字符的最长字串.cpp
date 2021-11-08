/*
problem:
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
example:
    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=-1, r=0, len=0, m[128];
        memset(m, -1, sizeof m);
        while (r < s.size())
        {
            l = max(l, m[s[r]]);
            len = max(len, r-l);
            m[s[r]] = r ++;
        }
        return max(len, r-l-1);
    }
};