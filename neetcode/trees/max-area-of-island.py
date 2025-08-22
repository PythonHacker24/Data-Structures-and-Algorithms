class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        self.maxIslandSize = 0
        ROWS, COLS = len(grid), len(grid[0])

        def dfs(r: int, c: int) -> int:
            count = 0
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == 0):
                return count

            grid[r][c] = 0
            count += 1

            count += dfs(r, c + 1)
            count += dfs(r, c - 1)
            count += dfs(r + 1, c)
            count += dfs(r - 1, c)

            return count

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    size = dfs(r, c)
                    if size > self.maxIslandSize:
                        self.maxIslandSize = size
        
        return self.maxIslandSize
