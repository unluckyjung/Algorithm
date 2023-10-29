import java.util.*

var t = 0
val s = Stack<Int>()
const val eraseCmd = 0

fun main() {
    t = readln().toInt()
    val result = solve()
    println(result)
}

fun solve(): Int {
    repeat(t) {
        val num = readln().toInt()
        if (num == eraseCmd) {
            s.pop()
        } else {
            s.push(num)
        }
    }
    return s.sum()
}
