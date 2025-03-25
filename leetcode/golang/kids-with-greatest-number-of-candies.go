func maximumCandy(candies []int) int {
    max := 0
    for _, candy := range candies {
        if candy > max { max = candy}
    }
    return max
}

func kidsWithCandies(candies []int, extraCandies int) []bool {
    maxCandy := maximumCandy(candies)
    solution := make([]bool, len(candies), len(candies))
    for i, candy := range candies {
        if (candy + extraCandies) >= maxCandy {
            solution[i] = true
        } else {
            solution[i] = false
        }
    }
    return solution
}
