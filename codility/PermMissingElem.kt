fun solution(arr: IntArray): Int {
    arr.sort()

    for (i in 0 until arr.size) {
        val num = arr[i]
        val target = i + 1
        if (target != num) return target
    }
    return arr.size + 1
}