func minimumBoxes(apple []int, capacity []int) int {
    var totalApples int
    for _, apples := range apple {
        totalApples += apples
    }

    sort.Sort(sort.Reverse(sort.IntSlice(capacity)))

    for index, cap := range capacity {
        totalApples = totalApples - cap
        if totalApples <= 0 {
            return index + 1
        }
    }

    return 0
}
