func findMaxAverage(nums []int, k int) float64 {
    var sum float64
    
    for i := 0; i < k; i++ {
        sum += float64(nums[i])
    }

    avg := sum / float64(k)
    maxAvg := avg 

    for i := k; i < len(nums); i++ {
        sum -= float64(nums[i - k])
        sum += float64(nums[i])

        avg = sum / float64(k)
        if avg > maxAvg { maxAvg = avg }
    }

    return maxAvg
}
