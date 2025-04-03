func closeStrings(word1 string, word2 string) bool {
    if len(word1) != len(word2) {
        return false
    }

    letters1 := make([]int, 26)
    letters2 := make([]int, 26)

    for _, letter := range word1 {
        letters1[int(letter) - 97] += 1
    }

    for _, letter := range word2 {
        letters2[int(letter) - 97] += 1
    }

    for i := 0; i < len(letters1); i++ {
        if (letters1[i] > 0) != (letters2[i] > 0) { return false }
    }

    sort.Ints(letters1)
    sort.Ints(letters2)
    for i:= 0; i < len(letters1); i++ {
        if letters1[i] != letters2[i] { return false}
    }

    return true
}
