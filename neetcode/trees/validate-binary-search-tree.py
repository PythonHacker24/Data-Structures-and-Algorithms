# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def validate(self, root: TreeNode, minVal: int, maxVal: int) -> bool:
        if not root:
            return True
        
        if (root.val <= minVal) or (root.val >= maxVal):
            return False

        return self.validate(root.left, minVal, root.val) and self.validate(root.right, root.val, maxVal)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.validate(root, -sys.maxsize - 1, sys.maxsize + 1)
        
