import random
class Solution(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        :type numsSize: int
        """
        self.nums = nums

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        arr = []
        n = len(self.nums)
        for i in range(0, n):
            if self.nums[i] == target:
                arr.append(i)
        a = random.sample(list(arr),1)
        return a[0]

num = [1,2,3,3,3]
obj = Solution(num)
param_1 = obj.pick(3)
print param_1



        # Your Solution object will be instantiated and called as such:
        # obj = Solution(nums)
        # param_1 = obj.pick(target)