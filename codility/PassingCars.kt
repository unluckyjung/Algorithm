fun solution(arr: IntArray): Int {
    val pivot = 1_000_000_000

    var rightCarCount: Long = 0
    var answer: Long = 0
    for (i in arr) {
        rightCarCount += i
    }

    for (i in arr) {
        if (i == 0) {
            answer += rightCarCount
            if (answer > pivot) return -1
        } else {
            rightCarCount--
        }
    }

    return answer.toInt()
}
