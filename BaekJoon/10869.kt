import java.util.*

val result = StringBuilder()

fun main() {
    solve()
}

private fun solve() {
    val line = StringTokenizer(readln())
    val num1 = line.nextToken().toInt()
    val num2 = line.nextToken().toInt()

    result.append("${num1 + num2}\n")
    result.append("${num1 - num2}\n")
    result.append("${num1 * num2}\n")
    result.append("${num1 / num2}\n")
    result.append("${num1 % num2}\n")
    println(result)
}