/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func maxDepth(root *TreeNode) int {
    if root == nil { return 0 }
    maxLeft := maxDepth(root.Left)
    maxRight := maxDepth(root.Right)
    return int(math.Max(float64(maxLeft), float64(maxRight))) + 1
}
