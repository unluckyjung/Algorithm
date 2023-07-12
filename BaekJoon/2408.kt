import java.util.*

fun main() {
    solve()
}


private fun solve() {
    val st = StringTokenizer(readln())
    val num1 = st.nextToken().toInt()
    val num2 = st.nextToken().toInt()
    val num3 = st.nextToken().toInt()

    if (num1 == num2 && num2 == num3) {
        println(10000 + num1 * 1000)
    } else if (num1 == num2 || num2 == num3) {
        println(1000 + num2 * 100)
    } else if (num1 == num3) {
        println(1000 + num1 * 100)
    } else {
        println(maxOf(num1, num2, num3) * 100)
    }
}
