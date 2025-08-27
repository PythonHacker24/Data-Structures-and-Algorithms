class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        if not grid:
            return None

        ROWS, COLS = len(grid), len(grid[0])
        
        def dfs(r: int, c: int, steps: int) -> None:
            if r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] < steps:
                return

            grid[r][c] = steps  

            dfs(r + 1, c, steps + 1)
            dfs(r - 1, c, steps + 1)
            dfs(r, c + 1, steps + 1)
            dfs(r, c - 1, steps + 1)

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    dfs(r, c, 0)  
