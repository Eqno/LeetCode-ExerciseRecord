/*
problem:
    给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。） 
    以这种方式修改数组后，返回数组可能的最大和。
example:
    输入：A = [4,2,3], K = 1
    输出：5
    解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++)
            if (k && nums[i]<0)
            {
                nums[i] = -nums[i];
                k --;
            }
        sort(nums.begin(), nums.end());
        if (k & 1) nums[0] = -nums[0];
        for (int i: nums) ans += i;
        return ans;
    }
};