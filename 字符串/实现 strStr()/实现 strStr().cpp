/*
problem:
    实现 strStr() 函数。
    给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
    说明：
    当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
    对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
example:
    输入：haystack = "hello", needle = "ll"
    输出：2
*/
class Solution {
public:
    int *getNext(const string &t)
    {
        int *next = new int[t.size()];
        int j = 0, k = -1; next[0] = -1;
        while (j < t.size()-1)
        {
            if (k==-1 || t[j]==t[k])
            {
                if (t[++j] == t[++k]) next[j] = next[k];
                else next[j] = k;
            }
            else k = next[k];
        }
        return next;
    }
    int kmp(const string &s, const string &t)
    {
        int i = 0, j = 0, *next = getNext(t);
        while (i<int(s.size()) && j<int(t.size()))
        {
            if (j==-1 || s[i]==t[j]) i++, j++;
            else j = next[j];
        }
        return (j==t.size()) ? (i-j) : -1;
    }
    int strStr(string haystack, string needle) {
        if (! needle.size()) return 0;
        return kmp(haystack, needle);
    }
};