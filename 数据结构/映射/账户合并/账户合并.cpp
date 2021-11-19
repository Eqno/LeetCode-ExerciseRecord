/*
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
*/
class Solution {
public:
    vector <int> f;
    int getf(int a) { return f[a]==a ? a : (f[a]=getf(f[a])); }
    void merge(int a, int b)
    {
        int fa = getf(a), fb = getf(b);
        if (fa != fb) f[fa] = fb;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector <string> str;
        vector <vector <int>> acc;
        unordered_map <string, int> ind;
        for (auto i: accounts)
        {
            acc.push_back(vector <int> ());
            for (auto j: i)
            {
                if (ind.find(j)==ind.end())
                {
                    str.push_back(j);
                    ind[j] = str.size()-1;
                }
                acc.back().push_back(ind[j]);
            }
        }
        vector <int> n(str.size());
        f = vector <int> (str.size());
        for (int i=0; i<f.size(); i++) f[i] = i;
        for (auto i: acc)
        {
            n[i[1]] = i[0];
            for (int j=2; j<i.size(); j++)
            {
                n[i[j]] = i[0];
                merge(i[j], i[j-1]);
            }
        }
        unordered_set <int> r;
        vector <set <string>> m(str.size());
        for (auto i: acc)
            for (int j=1; j<i.size(); j++)
            {
                f[i[j]] = getf(i[j]);
                r.insert(f[i[j]]);
                m[f[i[j]]].insert(str[i[j]]);
            }
        vector <vector <string>> ans;
        for (auto i: r)
        {
            ans.push_back(vector <string> ({str[n[ind[*m[i].begin()]]]}));
            for (auto j: m[i])
                ans.back().push_back(j);
        }
        return ans;
    }
};