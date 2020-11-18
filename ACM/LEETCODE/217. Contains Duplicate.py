#coding:utf-8
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums or len(nums) == 1:
            return False
        a = set()
        #print a  不能用 a = [] 这样会超时，研究下set()
        for i in nums:
            if i in a:
                return True
            a.add(i)
        return False
aa = Solution().containsDuplicate([3,1])
print aa