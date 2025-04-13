/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    count, result := 0, 0

    var preDFS func(node *TreeNode)
    preDFS = func(node *TreeNode) {
        if node == nil { return }

        preDFS(node.Left)
        count++ 
        if count == k { result = node.Val }
        preDFS(node.Right)
    }

    preDFS(root)
    return result
}
