func mergeAlternately(word1 string, word2 string) string {
    pt1 := 0
    pt2 := 0

    var solution string = ""

    // Check if pointers don't overflow the word lengths
    for pt1 < len(word1) && pt2 < len(word2) {
        solution += string(word1[pt1])
        pt1++
        solution += string(word2[pt2])
        pt2++
    }

    for pt1 < len(word1) {
        solution += string(word1[pt1])
        pt1++
    }

    for pt2 < len(word2) {
        solution += string(word2[pt2])
        pt2++
    }

    return solution
}
