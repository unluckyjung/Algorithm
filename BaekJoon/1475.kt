import java.util.*

val numCounts = MutableList(10) { 0 }

fun main() {
    val asciiDiff = '0' - 0

    val roomNumber = readln()
    for (charNum in roomNumber) {
        val num = charNum - asciiDiff
        numCounts[num]++
    }
    var maxCount = 0

    for (num in 0..9) {
        if (num == 6 || num == 9) continue
        maxCount = maxOf(maxCount, numCounts[num])
    }

    val sixCount = getNeedSixCount()
    println(maxOf(maxCount, sixCount))
}

private fun getNeedSixCount(): Int {
    var needSixCount = 0
    val sixCount = numCounts[6] + numCounts[9]

    if (sixCount != 0) {
        needSixCount = if (sixCount % 2 == 0) sixCount / 2
        else sixCount / 2 + 1
    }
    return needSixCount
}