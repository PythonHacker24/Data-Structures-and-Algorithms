func compress(chars []byte) int {
    var inputLength int = len(chars)
    var currentByte byte = chars[0]
    var occ int = 1
    writeIndex := 0

    if len(chars) == 1 {
        return 1
    }

    for index := 1; index < inputLength; index++ {
        if chars[index] == currentByte {
            occ += 1
            continue
        }

        chars[writeIndex] = currentByte
        writeIndex++

        if occ > 1 {
            for _, c := range []byte(strconv.Itoa(occ)) {
                chars[writeIndex] = c
                writeIndex++
            }
        }

        currentByte = chars[index]
        occ = 1
    }

    chars[writeIndex] = currentByte
    writeIndex++

    if occ > 1 {
        for _, c := range []byte(strconv.Itoa(occ)) {
            chars[writeIndex] = c
            writeIndex++
        }
    }

    return writeIndex
}
