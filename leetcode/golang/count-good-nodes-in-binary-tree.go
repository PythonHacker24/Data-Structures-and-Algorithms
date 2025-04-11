/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func DFS(node *TreeNode, count *int, max int) {
    if node == nil { return }
    
    if node.Val >= max {
        max = node.Val
        *count++
    }

    DFS(node.Left, count, max)
    DFS(node.Right, count, max)
}

func goodNodes(root *TreeNode) int {
    if root == nil { return 0 }
    if root.Left == nil && root.Right == nil { return 1 }

    var max int = root.Val
    var count int

    DFS(root, &count, max)
    return count
}
