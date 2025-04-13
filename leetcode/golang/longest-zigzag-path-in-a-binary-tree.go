/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestZigZag(root *TreeNode) int {
    return max(dfs(root.Left, true, 0), dfs(root.Right, false, 0))
}

func dfs(node *TreeNode, isLeft bool, count int) int {
    // if you have reached to the end of the tree, then just return the count
    if node == nil {
        return count
    }

    // If the parent node was in the left choice, it's time to go right now. Else, just start the count again
    if isLeft {
        return max(dfs(node.Left, true, 0), dfs(node.Right, false, count + 1))
    }

    // If the parent node was in the right choice, it's time to go to left now. Else, just start the count again
    return max(dfs(node.Left, true, count + 1), dfs(node.Right, false, 0))
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
