func longestSubarray(nums []int) int {
    i, j := 0, 0
    var zeroes int 
    for ; j < len(nums); j++ {
        zeroes += (1 - nums[j])    //  If there is any 0, zeroes will be added with 1
        if zeroes > 1 {
            zeroes -= (1 - nums[i])
            i++
        }
    }
    return j - i - 1
}
