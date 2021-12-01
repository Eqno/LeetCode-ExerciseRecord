"""
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
"""
class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        m = {'(':')', '[':']', '{':'}'}
        for i in s:
            if i in m.keys():
                st.append(i)
            elif len(st):
                t = st[len(st)-1]
                if m.get(t, '0') == i:
                    st.pop(len(st)-1)
                else:
                    return False
            else:
                return False
        return not len(st)