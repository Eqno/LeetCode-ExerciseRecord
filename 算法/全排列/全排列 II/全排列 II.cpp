// https://leetcode.cn/problems/permutations-ii/

class Solution {
public:
    vector<int> res, vis;
    vector<vector<int>> ans;
    void search(vector<int>& nums)
    {
        if (res.size() >= nums.size())
        {
            ans.emplace_back(res);
            return;
        }
        for (int i=0; i<nums.size(); i++)
        {
            if (vis[i] || i>0 && nums[i-1]==nums[i] && !vis[i-1]) continue;
            res.emplace_back(nums[i]);
            vis[i] = 1;
            search(nums);
            res.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vis.resize(nums.size());
        search(nums);
        return ans;
    }
};