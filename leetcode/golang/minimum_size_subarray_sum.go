func minSubArrayLen(target int, nums []int) int {
    l, total := 0, 0 
    res := 100001

    for index := range nums {
        total += nums[index]
        for total >= target {
            if index - l + 1 < res {
                res = index - l + 1
            }
            total -= nums[l]
            l += 1 
        }
    }
    if res != 100001 {
        return res 
    } 
    return 0
}
