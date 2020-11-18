class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str

        letters = [0] * 26
        for c in s:
            letters[ord(c) - 97] += 1
        for c in t:
            letters[ord(c) - 97] -= 1
            if letters[ord(c) - 97] < 0:
                return c
        """
        res = ord(t[-1])
        print(res,t[-5])
        for i in xrange(len(s)):
            res = res + ord(t[i]) - ord(s[i])
        return chr(res)
a = Solution()
print a.findTheDifference('abcd','abcde')