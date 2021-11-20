/*
problem:
    一个网站域名，如"discuss.leetcode.com"，包含了多个子域名。作为顶级域名，常用的有"com"，下一级则有"leetcode.com"，最低的一级为"discuss.leetcode.com"。当我们访问域名"discuss.leetcode.com"时，也同时访问了其父域名"leetcode.com"以及顶级域名 "com"。
    给定一个带访问次数和域名的组合，要求分别计算每个域名被访问的次数。其格式为访问次数+空格+地址，例如："9001 discuss.leetcode.com"。
    接下来会给出一组访问次数和域名组合的列表cpdomains 。要求解析出所有域名的访问次数，输出格式和输入格式相同，不限定先后顺序。
example:
    示例 1:
    输入: 
    ["9001 discuss.leetcode.com"]
    输出: 
    ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
    说明: 
    例子中仅包含一个网站域名："discuss.leetcode.com"。按照前文假设，子域名"leetcode.com"和"com"都会被访问，所以它们都被访问了9001次。
*/
class Solution {
public:
    int readNum(string s)
    {
        int num = 0;
        for (auto i: s)
        {
            if (i<'0' || i>'9') return num;
            num = num * 10 + i - '0';
        }
        return num;
    }
    void readString(string s, vector <string> &name)
    {
        int i = 0;
        for (; s[i]!=' '; i++);
        string tmp;
        for (int j=s.size()-1; j>i; j--)
        {
            if (s[j] == '.') name.push_back(tmp);
            tmp.push_back(s[j]);
        }
        name.push_back(tmp);
        for (int i=0; i<name.size(); i++)
            reverse(name[i].begin(), name[i].end());
    }
    string printNum(int num)
    {
        string res;
        while (num)
        {
            res.push_back(num%10+'0');
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map <string, int> m;
        for (auto i: cpdomains)
        {
            int num = readNum(i);
            vector <string> name;
            readString(i, name);
            for (auto j: name)
                m[j] += num;
        }
        vector <string> ans;
        for (auto i: m)
            ans.push_back(printNum(i.second)+" "+i.first);
        return ans;
    }
};