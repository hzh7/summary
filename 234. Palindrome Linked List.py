# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
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
        """
        if head == None or head.next == None:
            return True
        ptr1, ptr2, ptr3 = head, head, head
        while ptr1.next and ptr2.next.next:
            ptr1 = ptr1.next
            ptr2 = ptr2.next.next
        r, p = ptr1.next, ptr2
        while r == p:
            while r.next == p:
                r.next = p
                r.next = None
                p.next = r
                p = r
                r = ptr1.next
            r == r.next
        ptr1.next = None
        while ptr3.next:
            if ptr3.val != ptr2.val:
                return False
            ptr3 = ptr3.next
            ptr2 = ptr2.next
        return True
a = ListNode([1,2])
b = Solution().isPalindrome(a)
print b