func isValid(s string) bool {
    var stack []byte 
    stack = append(stack, s[0])
    for i := 1; i < len(s); i++ {
        comingByte := s[i]
        if len(stack) == 0 { 
            stack = append(stack, comingByte) 
            continue
        } 
        
        if stack[len(stack) - 1] == '(' {
            if comingByte == ')' {
                stack = stack[:len(stack) - 1]
            } else { stack = append(stack, comingByte) }
        } else if stack[len(stack) - 1] == '{' {
            if comingByte == '}' {
                stack = stack[:len(stack) - 1]
            } else { stack = append(stack, comingByte) }
        } else if stack[len(stack) - 1] == '[' {
            if comingByte == ']' {
                stack = stack[:len(stack) - 1]
            } else { stack = append(stack, comingByte) }
        } 
    }

    if len(stack) != 0 { return false}
    return true
}
