func reverseWords(s string) string {
    var words []string
    var word string
    for pt1 := 0; pt1 < len(s); pt1++ {
        if string(s[pt1]) == " " {
            if word != "" {
                words = append(words, word)
                word = ""
            }
            continue
        }
        word += string(s[pt1])
        if pt1 == len(s) - 1 { words = append(words, word) }
    }

    var output string 
    for index := 0; index < len(words); index++ {
        output += words[len(words) - 1 - index]
        if index != len(words) - 1 { output += " " }
    }

    return output
}
