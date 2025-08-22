# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    noPath = 0
    def preorder(self, root: TreeNode, lastGoodNode: int) -> None:
        if not root:
            return None

        if root.val >= lastGoodNode:
            self.noPath += 1
            lastGoodNode = root.val
        
        self.preorder(root.left, lastGoodNode)
        self.preorder(root.right, lastGoodNode)

    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return self.noPath

        # if last node was good, then current node must have value equal or greater than last node
        self.lastGoodNode = -sys.maxsize - 1
        self.preorder(root, self.lastGoodNode)

        return self.noPath


