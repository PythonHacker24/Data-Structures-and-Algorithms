/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func DFSPostOrder(node *TreeNode, count *int, max int) {
    if node == nil { return }
    
    if node.Val >= max {
        max = node.Val
        *count++
    }

    DFSPostOrder(node.Left, count, max)
    DFSPostOrder(node.Right, count, max)
}

func goodNodes(root *TreeNode) int {
    if root == nil { return 0 }
    if root.Left == nil && root.Right == nil { return 1 }

    var max int = root.Val
    var count int

    DFSPostOrder(root, &count, max)
    return count
}
