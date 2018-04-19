class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        v = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in v:
                return [v[diff],i]
            v[n] = i

a =Solution().twoSum([2, 7, 11, 15],9)
print a