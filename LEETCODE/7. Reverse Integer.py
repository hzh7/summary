#coding= utf-8
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        n = 0
        xx = abs(x)
        while xx > 0:
            xx = xx/10
            n += 1
        y = 0
        xx = abs(x)
        for i in range(n - 1, -1, -1):
            y = y + (xx % 10) * 10 ** i
            xx = xx / 10
        if x < 0:
            y = -y
        #以下注意，判断int型是否超出范围
        if y < -(1 << 31) or y > (1 << 31) - 1:
            return 0
        return y
    '''
    以下为网上代码
    def reverseInteger(self, n):
        if n == 0:
            return 0

        neg = 1
        if n < 0:
            neg, n = -1, -n

        reverse = 0
        while n > 0:
            reverse = reverse * 10 + n % 10
            n = n / 10

        reverse = reverse * neg
        if reverse < -(1 << 31) or reverse > (1 << 31) - 1:
            return 0
        return reverse
    '''
a = Solution().reverse(1534236469)
#a = Solution().reverseInteger(1534236469)
print a