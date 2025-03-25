func canPlaceFlowers(flowerbed []int, n int) bool {
    freepots := 0 
    
    for i, isplanted := range flowerbed {
        if isplanted == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == len(flowerbed) - 1 || flowerbed[i+1] == 0) {
            flowerbed[i] = 1
            freepots += 1
        }
        if freepots >= n {
            return true
        }
    }
    return false
}
