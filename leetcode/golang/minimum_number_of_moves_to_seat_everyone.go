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

func absolute(num1 int, num2 int) int {
    if num1 - num2 < 0 {
        return num2 - num1 
    } else {
        return num1 - num2 
    }
}

func minMovesToSeat(seats []int, students []int) int {
    quickSort(seats, 0, len(seats) - 1)
    quickSort(students, 0, len(seats) - 1)

    var counter int = 0 
    for index := range seats {
        counter += absolute(seats[index], students[index])
    }

    return counter
}
