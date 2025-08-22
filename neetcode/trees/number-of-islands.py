class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # if grid is not given, there cannot be islands
        if not grid:
            return 0

        # keep the count of islands here
        islands = 0
        ROWS, COLS = len(grid), len(grid[0])

        # define dfs here for marking the island with "0" to make sure we covered everything
        def dfs(r: int, c: int) -> None:
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or grid[r][c] == "0"):
                return
            
            # mark the place as visited by substituting zero there
            grid[r][c] = "0"
            dfs(r, c + 1)
            dfs(r, c - 1)
            dfs(r + 1, c)
            dfs(r - 1, c)

        # move through all regions until you get "1" and then, cover the land with "0" with dfs
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1":
                    dfs(r, c)
                    # island clear, increment the count
                    islands += 1

        # return the number of islands
        return islands
