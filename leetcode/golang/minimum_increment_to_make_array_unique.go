func pivot(array []int, pivotIndex int, endIndex int) int {
	var swapIndex int = pivotIndex
	for i := pivotIndex + 1; i <= endIndex; i++ {
		if (array[i] < array[pivotIndex]){
			swapIndex += 1
            array[swapIndex], array[i] = array[i], array[swapIndex]
		}
	}
    array[pivotIndex], array[swapIndex] = array[swapIndex], array[pivotIndex]
	return swapIndex
}

func quickSort(array []int, leftIndex int, rightIndex int) {
	if (leftIndex >= rightIndex) { return }

	var pivotIndex int = pivot(array, leftIndex, rightIndex)
	quickSort(array, leftIndex, pivotIndex - 1)
	quickSort(array, pivotIndex + 1, rightIndex)
}

func minIncrementForUnique(nums []int) int {
    quickSort(nums, 0, len(nums) - 1)
    
    var result int = 0
    for i := 1; i < len(nums); i++ {
        if nums[i - 1] >= nums[i] {
            result += 1 + nums[i - 1] - nums[i]
            nums[i] += 1 + (nums[i - 1] - nums[i])
        }
    }
    return result 
}
