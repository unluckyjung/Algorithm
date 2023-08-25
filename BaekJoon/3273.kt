import java.util.*

const val NUM_MAX_SIZE = 1000000
val numExist = MutableList(NUM_MAX_SIZE + 2) { false }
val nums = mutableListOf<Int>()

fun main() {
    val numCount = readln().toInt()
    val numsString = StringTokenizer(readln())

    repeat(numCount) {
        val num = numsString.nextToken().toInt()
        numExist[num] = true
        nums.add(num)
    }

    val targetNumber = readln().toInt()
    var answer = 0

    for (num in nums) {
        val needNumber = targetNumber - num
        if (needNumber <= 0 || needNumber > NUM_MAX_SIZE) continue
        if (numExist[needNumber].not()) continue
        if (needNumber == num) continue // 없어도 홀수개는 /2 에서 처리 되어 AC
        answer++
    }

    if (answer == 0) {
        println(answer)
    } else {
        println(answer / 2)
    }
}