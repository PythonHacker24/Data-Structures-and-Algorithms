func pivotIndex(nums []int) int {
    var sum int
    var leftsum int
    for _, value := range nums {
        sum += value
    }
    for index, value := range nums {
        if leftsum * 2 != (sum - value) { 
            leftsum += value
        } else {
            return index
        }
    }
    return -1
}
