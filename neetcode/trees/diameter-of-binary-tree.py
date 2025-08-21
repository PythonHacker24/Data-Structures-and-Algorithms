# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    diameter = 0
    def maxDepth(self, root):
        if not root:
            return 0
        
        ld = self.maxDepth(root.left)
        rd = self.maxDepth(root.right)

        self.diameter = max(self.diameter, ld + rd)

        return 1 + max(ld, rd)

    def diameterOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """

        self.maxDepth(root)
        return self.diameter

