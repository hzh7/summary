# coding=utf-8
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0],nums[1])
        else:
            return max(Solution().rob(nums[0:-1]),nums[-1]+Solution().rob(nums[0:-2]))
        """
        #Submission Result: Time Limit Exceeded ：以上代码递归 时间超时
        #以下参考后自己敲的
        n = len(nums)
        dp = [0] * (n+1)
        if nums:
            dp[1] = nums[0]
        for i in range(2, n+1):
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1])
        return dp[n]
        """以下网上参考代码
        size = len(nums)
        dp = [0] * (size + 1)
        if size:
            dp[1] = nums[0]
        for i in range(2, size + 1):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])
        return dp[size]
        """
num = [183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211]
#num = [1,2,4,7,3,9]
a = Solution().rob(num)
print(a)