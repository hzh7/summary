# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return
        if head.next == None:
            return head
        sec = head.next
        t, p = head, sec
        while t.next != None and p.next != None:
            t.next = p.next
            t = p.next
            p.next = t.next
            p = t.next
        return head
