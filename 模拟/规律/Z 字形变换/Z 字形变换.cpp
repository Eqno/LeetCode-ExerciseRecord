/*
problem:
    将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
    比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
    P   A   H   N
    A P L S I I G
    Y   I   R
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
    请你实现这个将字符串进行指定行数变换的函数：
    string convert(string s, int numRows);
example:
    输入：s = "PAYPALISHIRING", numRows = 4
    输出："PINALSIGYAHRPI"
    解释：
    P     I    N
    A   L S  I G
    Y A   H R
    P     I
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string ans;
        for (int i=0; i<numRows; i++)
        {
            int j = i, f = 1;
            while (j < s.size())
            {
                if (f) ans.push_back(s[j]);
                j += f = 2*(numRows-i-1);
                if (j < s.size())
                {
                    if (f) ans.push_back(s[j]);
                    j += f = 2 * i;
                }
            }
        }
        return ans;
    }
};