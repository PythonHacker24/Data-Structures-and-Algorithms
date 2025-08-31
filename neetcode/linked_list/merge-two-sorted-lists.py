# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None and list2 != None:
            return list2
        elif list2 == None and list1 != None:
            return list1
            
        fptr = list1
        sptr = list2
        newptr = None
        endptr = newptr

        while fptr != None and sptr != None:
            if fptr.val <= sptr.val:
                newNode = fptr
                fptr = fptr.next
            elif fptr.val > sptr.val:
                newNode = sptr
                sptr = sptr.next

            if not endptr:
                newptr = newNode
                endptr = newptr
            else:
                endptr.next = newNode
                endptr = endptr.next
        
        if fptr != None:
            endptr.next = fptr
        if sptr != None:
            endptr.next = sptr
        
        return newptr
