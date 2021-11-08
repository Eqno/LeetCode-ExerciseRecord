/*
problem:
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
example:
    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l=-1, r=0, len=0;
        int[] m = new int[128];
        for (int i=0; i<128; i++) m[i] = -1;
        while (r < s.length())
        {
            l = Math.max(l, m[s.charAt(r)]);
            len = Math.max(len, r-l);
            m[s.charAt(r)] = r ++;
        }
        return Math.max(len, r-l-1);
    }
}