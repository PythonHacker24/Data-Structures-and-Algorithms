func findDifference(nums1 []int, nums2 []int) [][]int {
    hashMap1 := make(map[int]bool)
    hashMap2 := make(map[int]bool)
    var exists bool
    result := make([][]int, 2)

    for _, value := range nums1 {
        hashMap1[value] = true
    }

    for _, value := range nums2 {
        _, exists = hashMap1[value]
        if !exists {
            result[1] = append(result[1], value)
            hashMap1[value] = true
        }
    }

    for _, value := range nums2 {
        hashMap2[value] = true
    }

    for _, value := range nums1 {
        _, exists = hashMap2[value]
        if !exists {
            result[0] = append(result[0], value)
            hashMap2[value] = true
        }
    }
    return result
}
