/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxLevelSum(root *TreeNode) int {
    if root.Left == nil && root.Right == nil { return 1 }
    var queue []*TreeNode 
    queue = append(queue, root)
    
    var maxSum int = root.Val
    var maxLevel int = 1
    var currentLevel int = 1

    for len(queue) > 0 {
        levelSize := len(queue)
        levelSum := 0
        
        for i := 0; i < levelSize; i++ {
            node := queue[0]
            queue = queue[1:]

            levelSum += node.Val

            if node.Left != nil {
                queue = append(queue, node.Left)
            }

            if node.Right != nil {
                queue = append(queue, node.Right)
            }
        }

        if levelSum > maxSum {
            maxSum = levelSum
            maxLevel = currentLevel
        }

        currentLevel++
    }

    return maxLevel
}
