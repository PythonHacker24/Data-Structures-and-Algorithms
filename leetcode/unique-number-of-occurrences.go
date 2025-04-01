func uniqueOccurrences(arr []int) bool {
    hashMap := make(map[int]int)
    for _, value := range arr {
        _, exists := hashMap[value]
        if !exists {
            hashMap[value] = 1
        } else {
            hashMap[value] += 1
        }
    }
    
    seen := make(map[int]bool)
    for _, value := range hashMap {
        if seen[value] {
            return false
        }
        seen[value] = true
    }
    return true
}
