func productExceptSelf(nums []int) []int {
    var result []int
    var zeroes int
    var product int = 1

    for _, value := range nums {
        if value == 0 {
            zeroes += 1
            continue 
        } else {
            product *= value
        }
    }

    for _, value := range nums {
        // if there are 2 or more zeroes, all the elements would be 0
        if zeroes > 1 {
            result = append(result, 0)
        } else if zeroes == 1 {
            if value == 0 {
                result = append(result, product)
            } else {
                result = append(result, 0)
            }
        } else {
            result = append(result, product / value)
        }
    }
    
    return result
}
