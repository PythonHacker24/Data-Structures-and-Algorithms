func equalPairs(grid [][]int) int {
    rows := make(map[int][]int)
    cols := make(map[int][]int)

    for i := 0; i < len(grid); i ++ {
        for j := 0; j < len(grid); j++ {
            rows[i] = append(rows[i], grid[i][j])
        }
    }

    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid); j++ {
            cols[i] = append(cols[i], grid[j][i])
        }
    }

    count := 0
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid); j++ {
            if slices.Equal(rows[i], cols[j]) {
                count++
            }
        }
    }

    return count   
}
