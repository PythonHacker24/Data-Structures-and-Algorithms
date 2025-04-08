/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    var leftPt int = 1
    var rightPt int = n
    var value int

    for leftPt <= rightPt {
        value = leftPt + (rightPt-leftPt) / 2 
        guessValue := guess(value)
        
        if guessValue == 0 {
            return value
        } else if guessValue == -1 {
            rightPt = value - 1
        } else {
            leftPt = value + 1
        }
    }
    
    return -1
}
