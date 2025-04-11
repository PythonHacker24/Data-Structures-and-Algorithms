/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func DFSPostOrder(node *TreeNode, leaves *[]int) {
	if node.Left != nil {
		DFSPostOrder(node.Left, leaves)
	}

	if node.Right != nil {
		DFSPostOrder(node.Right, leaves)
	}

	if node.Right == nil && node.Left == nil {
		*leaves = append(*leaves, node.Val)
	}
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var result1 []int
	var result2 []int

	DFSPostOrder(root1, &result1)
	DFSPostOrder(root2, &result2)

    if len(result1) != len(result2) { return false }

	for i := 0; i < len(result1); i++ {
		if result1[i] != result2[i] {
			return false
		}
	}

	return true
}
