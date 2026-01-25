import kotlin.math.max

fun solution(arr: IntArray): Int {
    arr.sort()
    val size = arr.size
    val candidate1 = arr[size - 1] * arr[size - 2] * arr[size - 3]
    val candidate2 = arr[0] * arr[1] * arr[size - 1]

    return max(candidate1, candidate2)
}