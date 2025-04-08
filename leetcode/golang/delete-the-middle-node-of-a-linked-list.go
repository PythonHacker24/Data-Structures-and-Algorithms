/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteMiddle(head *ListNode) *ListNode {
    // Calculating the length of the LinkedList
    var length int 
    tempHead := head
    for tempHead != nil {
        length++ 
        tempHead = tempHead.Next
    }

    // If the length is 1, return nil (empty LinkedList)
    if length == 1 { return nil }

    // Find the absolute middle
    var middle int = int(math.Abs(float64(length) / 2))

    // Follow up the the one element less then middle
    var tracker int 
    delPointer := head
    for tracker < middle - 1 {
        delPointer = delPointer.Next
        tracker++
    }

    // Link the next of the previous node of middle to the next of the middle
    garbage := delPointer.Next
    delPointer.Next = (delPointer.Next).Next

    // Disposing the garbage node for memory security purposes
    garbage.Next = nil

    return head
}
