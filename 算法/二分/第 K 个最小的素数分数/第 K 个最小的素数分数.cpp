/*
problem:
    给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。
    对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。
    那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。
example:
    输入：arr = [1,2,3,5], k = 3
    输出：[2,5]
    解释：已构造好的分数,排序后如下所示: 
    1/5, 1/3, 2/5, 1/2, 3/5, 2/3
    很明显第三个最小的分数是 2/5
*/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double L = 0, R = 1;
        while (1)
        {
            int cot = 0, x = 0, y = 0;
            for (int j=0; j<arr.size(); j++)
            {
                int l = 0, r = j;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (2*arr[m] < (L+R)*arr[j]) l = m + 1;
                    else r = m - 1;
                }
                cot += r + 1;
                if (r>=0 && x*arr[j]<=y*arr[r])
                    x = arr[r], y = arr[j];
            }
            if (cot == k) return {x, y};
            else if (cot < k) L = (L+R) / 2;
            else R = (L+R) / 2;
        }
    }
};