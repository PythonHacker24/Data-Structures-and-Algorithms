/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *TreeNode, val int) *TreeNode {
    if root.Left == nil && root.Right == nil {
        if root.Val == val { 
            return root 
        } 
        return nil 
    }

    var result *TreeNode
    var dfs func(node *TreeNode)

    dfs = func(node *TreeNode) {
        if node == nil { return }

        if node.Val == val {
            result = node 
            return 
        }

        dfs(node.Left)
        dfs(node.Right)
    }

    dfs(root)
    if result != nil {
        return result
    }

    return nil
}
