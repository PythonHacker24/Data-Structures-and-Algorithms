func moveZeroes(nums []int)  {
    var pos int 
    for pt2 := 0; pt2 < len(nums); pt2++ {
        if nums[pt2] != 0 {
            temp := nums[pos]
            nums[pos] = nums[pt2]
            nums[pt2] = temp
            pos++
        }
    }
}
