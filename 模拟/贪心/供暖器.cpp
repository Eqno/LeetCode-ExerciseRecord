/*
problem:
    冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
    在加热器的加热半径范围内的每个房屋都可以获得供暖。
    现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
    说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
example:
    输入: houses = [1,2,3], heaters = [2]
    输出: 1
    解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int lastPos = -1, ans = 0;
        for (int i=0; i<houses.size(); i++)
        {
            while (lastPos+1<heaters.size() && heaters[lastPos+1]<=houses[i])
                lastPos ++;
            if (lastPos >= 0)
            {
                int leftDis = houses[i] - heaters[lastPos];
                if (lastPos+1 < heaters.size())
                {
                    int rightDis = heaters[lastPos+1] - houses[i];
                    leftDis = min(leftDis, rightDis);
                }
                ans = max(ans, leftDis);
            }
            else
            {
                int rightDis = heaters[lastPos+1] - houses[i];
                ans = max(ans, rightDis);
            }
        }
        return ans;
    }
};