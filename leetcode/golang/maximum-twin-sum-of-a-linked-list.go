/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func pairSum(head *ListNode) int {
    result := 0
    var newList *ListNode 
    current := head 
    currentHalf := head 

    for currentHalf != nil && currentHalf.Next != nil {
        currentHalf = currentHalf.Next.Next 
        temp := current.Next 
        current.Next = newList
        newList = current 
        current = temp
    }

    for current != nil {
        result = int(math.Max(float64(result), float64(current.Val + newList.Val)))
        current = current.Next 
        newList = newList.Next 
    }

    return result
}
