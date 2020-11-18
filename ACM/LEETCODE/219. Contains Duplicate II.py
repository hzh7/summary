class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        a = {}
        for i, num in enumerate(nums): #*
            if num in a and i - a[num] <= k:
                return True
            a[num] = i #*
        return False
aa = Solution().containsNearbyDuplicate([-1,-1], 1)
print aa