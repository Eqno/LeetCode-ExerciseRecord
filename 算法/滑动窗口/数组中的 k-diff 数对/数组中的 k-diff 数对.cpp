// https://leetcode.cn/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i: nums) m[i] ++;
        vector<int> v; for (auto i: m) v.emplace_back(i.first);
        sort(v.begin(), v.end());
        int l = 0, r = 0, ans = 0;
        while (r < v.size())
        {
            while (l<r && v[r]-v[l]>k) l ++;
            if (v[r]-v[l]==k && (m[v[l]]>1 || l!=r)) ans ++;
            r ++;
        }
        return ans;
    }
};