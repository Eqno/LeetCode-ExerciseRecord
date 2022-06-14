// https://leetcode.cn/problems/find-and-replace-pattern/

class Solution {
public:
    void process(string& s)
    {
        int cot = 1;
        unordered_map<char, int> ind;
        for (int i=0; i<s.size(); i++)
        {
            if (ind[s[i]] == 0)
                ind[s[i]] = cot ++;
            s[i] = ind[s[i]];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        process(pattern);
        for (string s : words)
        {
            string str = s;
            process(str);
            if (str == pattern)
                ans.emplace_back(s);
        }
        return ans;
    }
};