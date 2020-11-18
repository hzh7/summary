class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        #n = len(nums)
        count, i, j, = 1, 1, 0
        while i < len(nums):
            if nums[j] < nums[i]:
                count += 1
                while i + 1 < len(nums) and nums[i + 1] >= nums[i]:
                    i += 1
            elif nums[j] > nums[i]:
                count += 1
                while i + 1 < len(nums) and nums[i + 1] <= nums[i]:
                    i += 1
            i, j = i + 1, i
        return count

a = Solution().wiggleMaxLength([1,7,4,9,2,5])
print(a)
'''
if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return 1
        if len(nums) == 2:
            if nums[1] == nums[0]:
                return 1
            return 2
        i = 1
        j = 2
        count = 2
        for j in range(2 , len(nums)):
            if nums[i] > nums[j] and nums[i-1] <= nums[j-1]:
                i += 1
                count += 1
            elif nums[i] < nums[j] and nums[i-1] >= nums[j-1]:
                i += 1
                count += 1
        #return count
'''