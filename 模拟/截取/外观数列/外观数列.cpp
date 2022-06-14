// https://leetcode.cn/problems/count-and-say/

class Solution {
public:
    string getNext(string s)
    {
        string res;
        int cot = 1, last = 0;
        for (char c : s)
        {
            if (c != last)
            {
                if (last)
                {
                    res += to_string(cot);
                    res.push_back(last);
                }
                cot = 1;
            }
            else cot ++;
            last = c;
        }
        res += to_string(cot);
        res.push_back(last);
        return res;
    }
    string countAndSay(int n) {
        string s = "1";
        while (n --> 1) s = getNext(s);
        return s;
    }
};