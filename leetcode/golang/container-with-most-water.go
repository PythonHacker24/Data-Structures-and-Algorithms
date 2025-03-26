func Min(x int, y int) int {
    if x > y { return y }
    return x
}

func calcArea(height []int, pt1 int, pt2 int) int {
    breath := Min(height[pt1], height[pt2])
    if pt1 > pt2 { return pt1 - pt2 * breath }
    return (pt2 - pt1) * breath
}

func maxArea(height []int) int {
    var pt1 int = 0
    var pt2 int = len(height) - 1
    var area int 

    var maxArea int 
    for pt1 != pt2 {
        if area = calcArea(height, pt1, pt2); area > maxArea {
            maxArea = area
        } else if height[pt1] > height[pt2] {
            pt2--
        } else {
            pt1++
        } 
    }
    return maxArea
}
