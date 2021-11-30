/*
problem:
    给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
    算法的时间复杂度应该为 O(log (m+n)) 。
example:
    输入：nums1 = [1,3], nums2 = [2]
    输出：2.00000
    解释：合并数组 = [1,2,3] ，中位数 2
    输入：nums1 = [1,2], nums2 = [3,4]
    输出：2.50000
    解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/
class Solution {
public:
    inline int query(int M, vector <int> &nums, int &r1, int &r2)
    {
        int l = 0, r = nums.size()-1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] < M) l = m + 1;
            else r = m - 1;
        }
        if (l < nums.size()) r1 = min(r1, nums[l]);
        if (r >= 0) r2 = max(r2, nums[r]);
        return r + 1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int K = len/2+(len&1), L = -1e6, R=1e6;
        while (L <= R)
        {
            int M = (L+R)>>1, r1 = 1e6, r2 = -1e6;
            int cot = query(M, nums1, r1, r2) + query(M, nums2, r1, r2);
            if (cot == K) return (len&1) ? r2 : (double)(r1+r2)/2;
            else if (cot < K) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};