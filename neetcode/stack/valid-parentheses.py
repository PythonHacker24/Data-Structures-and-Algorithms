class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False

        stack = []
        for bracket in s:
            if bracket == '(' or bracket == '[' or bracket == '{':
                stack.append(bracket)
            else:
                if len(stack) == 0:
                    return False
                elif bracket == ')':
                    if stack[len(stack) - 1] != '(':
                        return False
                elif bracket == ']':
                    if stack[len(stack) - 1] != '[':
                        return False
                elif bracket == '}':
                    if stack[len(stack) - 1] != '{':
                        return False
                stack = stack[:len(stack) - 1]

        if len(stack) != 0:
            return False

        return True
