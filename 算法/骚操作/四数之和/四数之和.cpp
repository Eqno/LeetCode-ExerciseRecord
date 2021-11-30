/*
problem:
    给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
    0 <= a, b, c, d < n
    a、b、c 和 d 互不相同
    nums[a] + nums[b] + nums[c] + nums[d] == target
    你可以按 任意顺序 返回答案 。
example:
    输入：nums = [1,0,-1,0,-2,2], target = 0
    输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    输入：nums = [2,2,2,2,2], target = 8
    输出：[[2,2,2,2]]
*/
class Solution {
public:
    struct HashPair
    { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    };
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        #define ll long long
        unordered_set <int> st1;
        vector <vector <int>> res;
        int HASHCODE = 17, MOD = 998244353;
        unordered_set <pair <int, int>, HashPair> st2;
        unordered_map <int, vector <pair <int, int>>> m;
        for (int i=0; i<nums.size(); i++)
            for (int j=i+1; j<nums.size(); j++)
            {
                int x = min(nums[i], nums[j]), y = max(nums[i], nums[j]);
                if (st2.find({x, y}) == st2.end())
                {
                    st2.insert({x, y});
                    m[nums[i]+nums[j]].push_back({i, j});
                }
            }
        for (int i=0; i<nums.size(); i++)
            for (int j=i+1; j<nums.size(); j++)
            {
                auto t = m.find(target-nums[i]-nums[j]);
                if (t != m.end()) for (auto p: (*t).second) if (i > p.second)
                {
                    vector <int> v({nums[i], nums[j], nums[p.first], nums[p.second]});
                    sort(v.begin(), v.end());
                    int hash = (((ll)v[0]*HASHCODE%MOD)*HASHCODE%MOD)*HASHCODE%MOD
                        + ((ll)v[1]*HASHCODE%MOD)*HASHCODE%MOD
                        + (ll)v[2]*HASHCODE%MOD + (ll)v[3];
                    if (st1.find(hash) == st1.end())
                    {
                        st1.insert(hash);
                        res.push_back(v);
                    }
                }
            }
        return res;
    }
};