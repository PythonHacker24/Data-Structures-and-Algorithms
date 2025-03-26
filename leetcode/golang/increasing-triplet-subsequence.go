func increasingTriplet(nums []int) bool {
    var first int = math.MaxInt32
    var second int = math.MaxInt32

    for _, num := range nums {
        if num <= first {
            first = num
        } else if num <= second {
            second = num
        } else {
            return true 
        }
    }

    return false 
}
