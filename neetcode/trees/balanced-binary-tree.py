# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        if not root:
            return 0, True

        ld, leftBal = self.maxDepth(root.left)
        rd, rightBal = self.maxDepth(root.right)

        if not leftBal or not rightBal or abs(ld - rd) > 1:
            return 1 + max(ld, rd), False

        return 1 + max(ld, rd), True

    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """

        depth, isBal = self.maxDepth(root)
        return isBal
