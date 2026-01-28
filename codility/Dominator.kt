import java.util.*

fun solution(arr: IntArray): Int {
    val map = HashMap<Int, Int>()
    var maxCount = 0
    var maxNum = 0

    for (num in arr) {
        map[num] = (map[num] ?: 0) + 1
        val count = map[num]!!

        if (count > maxCount) {
            maxNum = num
            maxCount = count
        }
    }

    val totalSize = arr.size
    if (maxCount <= totalSize / 2) return -1
    else {
        for (index in 0 until arr.size) {
            if (arr[index] == maxNum) return index
        }
        return -1
    }
}