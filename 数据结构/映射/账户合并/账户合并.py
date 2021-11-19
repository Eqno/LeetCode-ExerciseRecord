'''
problem:
    给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。
    现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
    合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 按字符 ASCII 顺序排列 的邮箱地址。账户本身可以以 任意顺序 返回。
example:
    输入：accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
    输出：[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
    解释：
    第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
    第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
    可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
    ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
'''
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        f = {}
        def getf(a):
            if a not in f:
                f[a] = a
            if f[a] == a:
                return a
            else:
                f[a] = getf(f[a])
                return f[a]
        def merge(a, b):
            fa = getf(a)
            fb = getf(b)
            if fa != fb:
                f[fa] = fb
        n = {}
        for i in accounts:
            n[i[1]] = i[0]
            for j in range(2, len(i)):
                n[i[j]] = i[0]
                merge(i[1], i[j])
        m = {}
        for i in accounts:
            for j in range(1, len(i)):
                f[i[j]] = getf(i[j])
                if f[i[j]] not in m:
                    m[f[i[j]]] = set()
                m[f[i[j]]].add(i[j])
        ans = []
        for k, v in m.items():
            ans.append([n[k]]+sorted(list(v)))
        return ans