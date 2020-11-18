# coding=utf-8
class NumMatrix(object):
    '''
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        self.matrix = matrix

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        if row1 > row2 or col1 > col2:
            return None
        sum = 0
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                sum = sum + self.matrix[i][j]
        return sum
        #以上: Time Limit Exceeded
    '''

    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        self.false_input = not matrix or not matrix[0]
        if self.false_input: return
        m, n = len(matrix) + 1, len(matrix[0]) + 1
        self.sum = [[0 for j in xrange(n)] for i in xrange(m)]
        #print self.sum
        for i in xrange(1, m):
            for j in xrange(1, n):
                self.sum[i][j] = self.sum[i][j - 1] + matrix[i - 1][j - 1]

        for i in xrange(1, m):
            for j in xrange(1, n):
                self.sum[i][j] = self.sum[i - 1][j] + self.sum[i][j]

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        if self.false_input: return 0
        return self.sum[row2 + 1][col2 + 1] - self.sum[row2 + 1][col1] - self.sum[row1][col2 + 1] \
               + self.sum[row1][col1]

matrix = [
            [3, 0, 1, 4, 2],
            [5, 6, 3, 2, 1],
            [1, 2, 0, 1, 5],
            [4, 1, 0, 1, 7],
            [1, 0, 3, 0, 5]
        ]
        # Your NumMatrix object will be instantiated and called as such:
numMatrix = NumMatrix(matrix)
a = numMatrix.sumRegion(0, 1, 2, 3)
b = numMatrix.sumRegion(1, 2, 3, 4)
m, n = len(matrix) + 1, len(matrix[0]) + 1
print a, b, m, n
print numMatrix.sum