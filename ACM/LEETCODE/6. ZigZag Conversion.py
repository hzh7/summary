class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows >= len(s) or numRows == 1:
            return s
        arr = [[] for i in range(numRows)]

        for i in range(0, len(s)):
            arr[numRows - 1 - abs(i%(2*numRows - 2)-numRows+1)].append(i)
        print arr
        ss = s[0]
        for i in range(0, numRows):
            for j in range(0, len(arr[i])):
                ss = str(ss)+s[int(arr[i][j])]
        ss = ss[1:]
        return ss
        #return "".join(["".join(s[i]) for i in xrange(numRows)])
#arr[0][0 : ]
#a = Solution().convert("PAYPALISHIRING", 3)
a = Solution().convert("ddd", 1)
print a