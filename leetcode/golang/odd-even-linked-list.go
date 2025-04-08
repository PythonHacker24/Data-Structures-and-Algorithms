/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    
    // Handling edge cases
    if head == nil { return nil }
    if head.Next == nil { return head }

    // Find the last node 
    last := head 
    var attempts int
    for last.Next != nil {
        last = last.Next
        attempts++
    }

    attempts = int(math.Abs(float64(attempts + 1) / 2))

    follower := head 
    count := 0
    for count < attempts {
        last.Next = follower.Next
        follower.Next = (last.Next).Next
        (last.Next).Next = nil

        follower = follower.Next
        last = last.Next
        count++
    }

    return head
}
