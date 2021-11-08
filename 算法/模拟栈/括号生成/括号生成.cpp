/*
problem:
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
    有效括号组合需满足：左括号必须以正确的顺序闭合。
example:
    输入：n = 3
    输出：["((()))","(()())","(())()","()(())","()()()"]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack <pair <pair <int, int>, string>> st;
        st.push(make_pair(make_pair(0, 0), ""));
        while (! st.empty())
        {
            pair <pair <int, int>, string> p = st.top();
            st.pop();
            if (p.second.size() == 2*n)
            {
                ans.push_back(p.second);
                continue ;
            }
            int l = p.first.first, r = p.first.second;
            if (l < n) st.push(make_pair(make_pair(l+1, r), p.second+"("));
            if (r < l) st.push(make_pair(make_pair(l, r+1), p.second+")"));
        }
        return ans;
    }
};