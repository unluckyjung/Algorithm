fun solution(arr: IntArray): Int {
    arr.sort()
    for (i in 0 until arr.size) {
        val num = arr[i]
        if (num != i + 1) return 0
    }
    return 1
}

fun solution2(arr: IntArray): Int {
    val m = TreeMap<Int, Boolean>()

    for (num in arr) {
        if (m[num] == null) {
            m[num] = true
        } else {
            return 0
        }
    }

    return if (m.size == arr.size && m.lastKey() == arr.size) 1
    else 0
}
