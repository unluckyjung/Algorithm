fun solution(arr: IntArray, n: Int): IntArray {
    if (arr.isEmpty()) return arr

    // Implement your solution here
    val rotateCount = n % arr.size
    val answer = IntArray(arr.size)

    val dq = ArrayDeque<Int>()

    for (num in arr) {
        dq.addLast(num)
    }

    repeat(rotateCount) {
        dq.addFirst(dq.removeLast())
    }

    for (i in 0 until dq.size) {
        answer[i] = dq[i]
    }

    return answer
}
