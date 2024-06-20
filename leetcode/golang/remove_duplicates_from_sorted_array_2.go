func removeDuplicates(nums []int) int {
    var occurance int = 1
    var index int = 1
    for i := 1; i < len(nums); i++ {
        if (nums[i] == nums[i - 1]) { 
            occurance += 1
        } else {
            occurance = 1
        }
        if occurance <= 2 {
            nums[index] = nums[i]
            index += 1
        }
    }   
    return index 
}
