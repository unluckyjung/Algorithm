import java.util.*

fun solution(fishSizes: IntArray, fishDirs: IntArray): Int {
    val dq = ArrayDeque<Int>()
    var answer = 0

    for (i in 0 until fishSizes.size) {
        val fishSize = fishSizes[i]
        val fishDir = fishDirs[i]

        if (fishDir == 0) {
            if (dq.isEmpty()) {
                answer++
                continue
            } else {
                while (dq.isNotEmpty()) {
                    val topFishSize = dq.peekLast()
                    // 입력으로 물고기 사이즈 같은케이스 없음.
                    if (fishSize > topFishSize) dq.removeLast()
                    else break
                }
                if (dq.isEmpty()) answer++
            }
        } else {
            dq.addLast(fishSize)
        }
    }
    return answer + dq.size
}