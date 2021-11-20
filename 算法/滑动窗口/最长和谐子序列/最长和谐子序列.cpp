/*
problem:
    和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
    现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
    数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
example:
    输入：nums = [1,3,2,2,5,2,3,7]
    输出：5
    解释：最长的和谐子序列是 [3,2,2,2,3]
*/
class Solution {
public:
    unordered_map <int, int> m;
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i=0, j=0; j<nums.size(); j++)
        {
            while (i<j && nums[j]-nums[i]>1) i++;
            if (nums[j]-nums[i]) ans = max(ans, j-i+1); 
        }
        return ans;
    }
};