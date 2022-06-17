// https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int L = 0, R = nums.back()-nums.front();
        while (L <= R)
        {
            int M = (L + R) >> 1, cot = 0;
            for (int i=0; i<nums.size(); i++)
            {
                int l = 0, r = i;
                while (l <= r)
                {
                    int m = (l + r) >> 1;
                    if (nums[i]-nums[m] > M) l = m + 1;
                    else r = m - 1;
                }
                cot += i - l;
            }
            if (cot >= k) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};