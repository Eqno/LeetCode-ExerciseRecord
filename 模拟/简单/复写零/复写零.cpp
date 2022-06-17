// https://leetcode.cn/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> v(arr);
        arr.resize(0);
        for (int i: v)
        {
            arr.emplace_back(i);
            if (arr.size() >= v.size()) break;
            if (! i) arr.emplace_back(0);
            if (arr.size() >= v.size()) break;
        }
    }
};