# https://leetcode.cn/problems/permutations/submissions/

class Solution:    
    def search(self, nums, index, ans):
        if index >= len(nums):
            ans.append(copy.deepcopy(nums))
            return
        for i in range(index, len(nums)):
            nums[i], nums[index] = nums[index], nums[i]
            self.search(nums, index + 1, ans)
            nums[i], nums[index] = nums[index], nums[i]
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.search(nums, 0, ans)
        return ans