# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False

        tortoise, hare = head, head

        while hare != None and hare.next != None:
            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                return True
        
        return False
