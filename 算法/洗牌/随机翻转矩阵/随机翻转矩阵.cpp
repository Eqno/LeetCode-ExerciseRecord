/*
problem:
    给你一个 m x n 的二元矩阵 matrix ，且所有值被初始化为 0 。请你设计一个算法，随机选取一个满足 matrix[i][j] == 0 的下标 (i, j) ，并将它的值变为 1 。所有满足 matrix[i][j] == 0 的下标 (i, j) 被选取的概率应当均等。
    尽量最少调用内置的随机函数，并且优化时间和空间复杂度。
    实现 Solution 类：
    Solution(int m, int n) 使用二元矩阵的大小 m 和 n 初始化该对象
    int[] flip() 返回一个满足 matrix[i][j] == 0 的随机下标 [i, j] ，并将其对应格子中的值变为 1
    void reset() 将矩阵中所有的值重置为 0
example:
    输入
    ["Solution", "flip", "flip", "flip", "reset", "flip"]
    [[3, 1], [], [], [], [], []]
    输出
    [null, [1, 0], [2, 0], [0, 0], null, [2, 0]]
    解释
    Solution solution = new Solution(3, 1);
    solution.flip();  // 返回 [1, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
    solution.flip();  // 返回 [2, 0]，因为 [1,0] 已经返回过了，此时返回 [2,0] 和 [0,0] 的概率应当相同
    solution.flip();  // 返回 [0, 0]，根据前面已经返回过的下标，此时只能返回 [0,0]
    solution.reset(); // 所有值都重置为 0 ，并可以再次选择下标返回
    solution.flip();  // 返回 [2, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
*/
class Solution {
private:
    int m, n, parSize, matSize;
    vector <unordered_set <int>> part;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        matSize = m * n;
        parSize = sqrt(matSize);
        part.resize(matSize/parSize+1);
        srand(time(nullptr));
    }
    vector<int> flip() {
        int x = rand()%matSize, sum = 0, cur = 0;
        matSize --;
        for (auto &par: part)
        {
            if (sum+parSize-par.size() > x)
                for (int i=0; i<parSize; i++)
                    if (par.find(cur+i) == par.end())
                    {
                        if (sum == x)
                        {
                            par.emplace(cur+i);
                            return {(cur+i)/n, (cur+i)%n};
                        }
                        sum ++;
                    }
            cur += parSize;
            sum += parSize - par.size();
        }
        return {};
    }
    void reset() {
        for (auto &par: part)
            par.clear();
        matSize = m * n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */