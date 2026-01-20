import kotlin.math.*

fun solution(arr: IntArray): Int {
    var sum = 0
    var leftSum = 0
    for (num in arr) sum += num

    var minDiff = Int.MAX_VALUE

    for (i in 0 until arr.size - 1) {
        val num = arr[i]
        leftSum += num
        val rightSum = sum - leftSum
        val candidate = abs(leftSum - rightSum)

        minDiff = min(minDiff, candidate)
    }
    return minDiff
}