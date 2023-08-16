import java.io.BufferedReader
import java.util.*

val sb = StringBuilder()
val t = 5
val nums = MutableList(5) { 0 }

fun main() {
    solve()
    println(sb)
}

private fun solve() {
    repeat(t) {
        val num = readln().toInt()
        nums[it] = num
    }
    nums.sort()
    sb.append(nums.average().toInt()).append("\n")
    sb.append(nums[2])
}