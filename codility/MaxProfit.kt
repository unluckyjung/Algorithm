import kotlin.math.*

fun solution(arr: IntArray): Int {
    var answer = 0
    var currentMin = 400_001

    for (price in arr) {
        if (price < currentMin) {
            currentMin = price
        } else {
            val diff = price - currentMin
            answer = max(answer, diff)
        }
    }

    return answer
}