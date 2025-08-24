"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
from collections import deque

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        # if not node, return None
        if not node:
            return None

        # map old nodes to new node to keep a track
        old_to_new = {node: Node(node.val)}

        # create queue necessary for bfs
        queue = deque()
        queue.append(node)

        # traverse the queue
        while queue:
            for i in range(len(queue)):
                curr = queue.popleft()
                
                for neighbor in curr.neighbors:
                    if neighbor not in old_to_new:
                        old_to_new[neighbor] = Node(neighbor.val)
                        queue.append(neighbor)
                    
                    old_to_new[curr].neighbors.append(old_to_new[neighbor])

        return old_to_new[node]        
