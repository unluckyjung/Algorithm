fun solution(arr: IntArray): Int {
    var leaderNum = -1_000_000_001
    var maxCount = 0
    val visitedCount = HashMap<Int, Int>()

    for (num in arr) {
        visitedCount[num] = (visitedCount[num] ?: 0) + 1
    }

    for ((num, count) in visitedCount) {
        if (count > maxCount) {
            maxCount = count
            leaderNum = num
        }
    }
    if (maxCount <= arr.size / 2) {
        return 0
    }

    val leaderNumTotalCount = maxCount
    var leftLeaderCount = 0
    var answer = 0

    for (i in 0 until arr.size - 1) {
        if (arr[i] == leaderNum) {
            leftLeaderCount++
        }
        val rightLeaderCount = leaderNumTotalCount - leftLeaderCount
        val leftTotalCount = i + 1
        val rightTotalCount = arr.size - leftTotalCount
        if ((leftTotalCount / 2 < leftLeaderCount) && (rightTotalCount / 2 < rightLeaderCount)) {
            answer++
        }
    }
    return answer
}