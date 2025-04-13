/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, targetSum int) int {
    return countPaths(root, targetSum, []int{})
}

// This function calculates sum sum for all possible paths from a node 
func countPaths(root *TreeNode, target int, path []int) int {
    counter := 0
    if root == nil { return counter }

    path = append(path, root.Val)
    sum := 0

    for i := len(path) - 1; i >= 0; i-- {
        sum += path[i]
        if sum == target {
            counter++
        }
    }

    return counter + countPaths(root.Left, target, path) + countPaths(root.Right, target, path)
}
