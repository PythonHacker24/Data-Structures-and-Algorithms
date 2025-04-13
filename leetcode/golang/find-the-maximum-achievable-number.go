func theMaximumAchievableX(num int, t int) int {
    if t < 1 { return num }
    return num + 2 * t
}
