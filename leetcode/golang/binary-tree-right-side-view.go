/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) []int {
    var result []int

    // If root is nil - no tree
    if root == nil { return result }

    // if only root is present
    if root.Left == nil && root.Right == nil {
        result = append(result, root.Val)
        return result 
    }

    var queue []*TreeNode

    queue = append(queue, root)

    for len(queue) > 0 {
        levelSize := len(queue)
        for i := 0; i < levelSize; i++ {
            // Get the first value from the queue
            currNode := queue[0]
            
            // Pop the queue 
            queue = queue[1:]

            if currNode.Left != nil {
                queue = append(queue, currNode.Left)
            }

            if currNode.Right != nil {
                queue = append(queue, currNode.Right)
            }

            if i == levelSize - 1 {
                result = append(result, currNode.Val)
            }
        }
    }

    return result
}

/*
- Let the index of the slice be the depth of the tree - result
- So I will need to add the rightmost value in the tree to the slice
- 
*/
