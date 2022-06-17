// https://leetcode.cn/problems/multiply-strings/

class Solution {
public:
    string add(string a, string b)
    {
        string res;
        int i = a.size()-1, j = b.size()-1, f = 0;
        while (i >= 0 || j >= 0)
        {
            int d = 0;
            if (i >= 0 && j >= 0)
                d = a[i]-'0' + b[j]-'0' + f, i --, j--;
            else if (i >= 0) d = a[i]-'0' + f, i--;
            else if (j >= 0) d = b[j]-'0' + f, j--;
            f = d >= 10, d %= 10;
            res.push_back(d+'0');
        }
        if (f) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        string ans;
        for (int i=0; i<num2.size(); i++)
        {
            string res;
            for (int j=0; j<num1.size(); j++)
            {
                string tmp;
                int dig = (num2[i]-'0') * (num1[j]-'0');
                while (dig)
                {
                    tmp.push_back(dig%10+'0');
                    dig /= 10;
                }
                reverse(tmp.begin(), tmp.end());
                res = add(res+"0", tmp);
            }
            ans = add(ans+"0", res);
        }
        bool flag = true;
        for (char i: ans) if (i != '0') flag = false;
        if (flag) ans = "0";
        return ans;
    }
};