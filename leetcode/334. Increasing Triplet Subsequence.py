class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """'''
        if len(nums) <= 2:
            return False
        dp = [0]*len(nums)
        for i in range(len(nums)):
            max_dp = 0
            for j in range(0, i):
                if nums[j] < nums[i]:
                    if max_dp < dp[j]:
                        max_dp = dp[j]
            dp[i] = max_dp + 1

        print dp
        if max(dp) >= 3:
            return True
        return False
    '''
        a = b = None
        for n in nums:
            if a == None or a >= n:
                a = n
            elif b == None or b >= n:
                b = n
            else:
                return True
        return False
n = [2, 1, 5, 0, 4, 6]
a = Solution().increasingTriplet(n)
#print max(n[0 : 3])
print a