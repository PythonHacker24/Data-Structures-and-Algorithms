func largestAltitude(gain []int) int {
    altitudes := []int{0}
    var altitude int 
    var maxaltitude int
    for index, value := range gain {
        altitude = altitudes[index] + value
        if altitude > maxaltitude { maxaltitude = altitude }
        altitudes = append(altitudes, altitude)
    }
    return maxaltitude
}
