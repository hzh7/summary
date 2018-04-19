class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int

        if not nums:
            return 0
        k = 1
#        n = len(nums)
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1]:
#                nums[k] = nums[i]
                k += 1
        return k
#        a = set(nums)
#        return len(a)"""


        k, n = 1, len(nums)
        for i in range(1, n):
            if nums[i] != nums[i - 1]:
                nums[k] = nums[i]
                k += 1
        return min(k, n)

aa = Solution().removeDuplicates([1,1,2])
print aa

