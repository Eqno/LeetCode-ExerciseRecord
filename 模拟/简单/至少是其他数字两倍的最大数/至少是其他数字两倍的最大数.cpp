/*
problem:
    给你一个整数数组 nums，其中总是存在唯一的一个最大整数。
    请你找出数组中的最大元素并检查它是否至少是数组中每个其他数字的两倍。如果是，则返回最大元素的下标，否则返回 -1。
example:
    输入：nums = [3,6,1,0]
    输出：1
    解释：6 是最大的整数，对于数组中的其他整数，6 大于数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
*/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxn=-1, maxl=0, smxn=-1;
        for (int i=0; i<nums.size(); i++)
        if (nums[i] > maxn)
        {
            smxn = max(smxn, maxn);
            maxn = nums[maxl=i];
        }
        else smxn = max(smxn, nums[i]);
        return (smxn*2<=maxn) ? maxl: -1;
    }
};