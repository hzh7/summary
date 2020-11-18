class Solution(object):

    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        return self.testPick(dp, 1, n)
    def testPick(self, dp, l, r):
        if l >=r:return 0
        if dp[l][r]:
            return dp[l][r]
        dp[l][r] = min(i + max(self.testPick(dp, l, i - 1), self.testPick(dp, i + 1, r)) for i in range(l, r + 1))
        return dp[l][r]