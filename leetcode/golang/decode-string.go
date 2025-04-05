type item struct {
    n       int 
    bytes   []byte
}

func decodeString(s string) string {    
    num := 0
    stack := []item{{1, []byte{}}}

    for i := range s {
        switch {
            case s[i] == '0':
                num *= 10
            case s[i] > '0' && s[i] <= '9':
                num = num*10 + int(s[i] - '0')       // important step
            case s[i] == '[':
                stack = append(stack, item{num, []byte{}}) 
                num = 0
            case s[i] == ']':
                tmp := stack[len(stack) - 1]
                stack = stack[:len(stack) - 1]
                for j := 0; j < tmp.n; j++ {
                    stack[len(stack) - 1].bytes = append(stack[len(stack) - 1].bytes, tmp.bytes...)
                }
            default:
                stack[len(stack) - 1].bytes = append(stack[len(stack) - 1].bytes, s[i])
        }
    }

    return string(stack[0].bytes)
}
