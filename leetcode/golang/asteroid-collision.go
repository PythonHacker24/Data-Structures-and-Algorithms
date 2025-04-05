func asteroidCollision(asteroids []int) []int {
    stack := []int{asteroids[0]}

    for i := 1; i < len(asteroids); i++ {
        for len(stack) > 0 && stack[len(stack) - 1] > 0 && stack[len(stack) - 1] < -asteroids[i] {
            stack = stack[:len(stack) - 1]
        }

        if len(stack) == 0 || stack[len(stack) - 1] < 0 || asteroids[i] > 0 {
            stack = append(stack, asteroids[i])
        }

        if stack[len(stack) - 1] == -asteroids[i] {
            stack = stack[:len(stack)-1]
        }
    }
    return stack
}
