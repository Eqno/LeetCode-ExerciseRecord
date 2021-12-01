/*
problem:
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
example:
    输入：s = "()"
    输出：true
    输入：s = "()[]{}"
    输出：true
*/
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (auto i: s)
        {
            if (i=='(' || i=='[' || i=='{') st.push(i);
            else if (st.size())
            {
                char t = st.top();
                if (t=='('&&i==')' || t=='['&&i==']' || t=='{'&&i=='}')
                    st.pop();
                else return false; 
            }
            else return false;
        }
        return !st.size();
    }
};