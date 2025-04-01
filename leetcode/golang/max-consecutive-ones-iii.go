func longestOnes(nums []int, k int) int {
    i, j := 0, 0
    for j < len(nums) {
        if nums[j] == 0 {
            k--
        }
        j++
        if k < 0 {
            if nums[i] == 0 {
                k++
            }
            i++
        }
    }
    return j - i
}
