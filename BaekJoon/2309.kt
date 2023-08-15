import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val sb = StringBuilder()
val talls = MutableList(9) { 0 }

fun main() {
    solve()
    println(sb)
}

private fun solve() {
    var totalSum = 0

    repeat(9) {
        val tall = readln().toInt()
        talls[it] = tall
        totalSum += tall
    }
    talls.sort()

    for (fake1Index in 0 until 9) {
        for (fake2Index in fake1Index until 9) {
            if (totalSum - talls[fake1Index] - talls[fake2Index] == 100) {
                talls.forEachIndexed { index, tall ->
                    if (index != fake1Index && index != fake2Index) {
                        sb.append(tall).append("\n")
                    }
                }
                return
            }
        }
    }
}