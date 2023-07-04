import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val count = readln().toInt()
    val sb = StringBuilder()
    repeat(count) {
        val st = StringTokenizer(readln())
        val n = st.nextToken().toInt()
        val m = st.nextToken().toInt()
        sb.append(n + m).append("\n")
    }
    println(sb)
}