# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return True
        i, j = 0, len(head) - 1
        while i <= j:
            if head[i] == head[j]:
                i += 1
                j -= 1
            else:
                return False
        return True
a = ["a","g","s","s","g","a"]
b = Solution().isPalindrome(a)
print b