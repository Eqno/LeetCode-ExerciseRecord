// https://leetcode.cn/problems/permutations/

class Solution {
public:
    vector<vector<int>> ans;
    void search(vector<int> &nums, int index)
    {
        if (index >= nums.size())
        {
            ans.emplace_back(nums);
            return;
        }
        for (int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            search(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        search(nums, 0);
        return ans;
    }
};