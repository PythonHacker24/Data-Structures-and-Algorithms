func isVowel(s byte) bool {
    vowels := []byte{'a', 'e', 'i', 'o', 'u'}
    for k := 0; k < 5; k++ {
        if vowels[k] == s { return true }
    }
    return false
}

func maxVowels(s string, k int) int {
    var count int

    for i := 0; i < k; i++ {
        if isVowel(s[i]) { count++ }
    }

    maxCount := count

    for i := k; i < len(s); i++ {
        if isVowel(s[i - k]) { count -= 1 }
        if isVowel(s[i]) { count += 1}

        if count > maxCount { maxCount = count }
    }

    return maxCount
}
