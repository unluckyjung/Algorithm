import java.util.*

fun solution(target: Int, arr: IntArray): Int {
    val s = TreeSet<Int>()

    for (i in 0 until arr.size) {
        s.add(arr[i])
        if (s.size >= target) return i
    }
    return -1
}