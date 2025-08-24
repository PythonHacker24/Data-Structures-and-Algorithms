from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        queue = deque()

        ROWS, COLS = len(grid), len(grid[0])

        fresh = 0
        # for minute zero
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    queue.append({0: [r, c]})
                if grid[r][c] == 1:
                    fresh += 1

        # direction of traversal
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]

        maxTime = 0
        while len(queue) > 0:
            currRotten = queue.popleft()
            
            for i in range(4):
                keys = list(currRotten.keys())
                nrow = currRotten[keys[0]][0] - dy[i]
                ncol = currRotten[keys[0]][1] - dx[i]
                time = keys[0]
                maxTime = max(time, maxTime)

                if nrow >= 0 and ncol >= 0 and nrow < ROWS and ncol < COLS and grid[nrow][ncol] == 1 and grid[nrow][ncol] != 0:
                        queue.append({time + 1: [nrow, ncol]})
                        fresh -= 1
                        grid[nrow][ncol] = 0
            
        if fresh != 0:
            return -1
            
        return maxTime
