import java.util.*

var sb = StringBuilder()
var t = 0
var curNum = 0
val s = Stack<Int>().apply { this.push(0) }

fun main() {
    t = readln().toInt()
    val result = solve()
    println(result)
}

fun solve(): String {
    repeat(t) {
        val needNum = readln().toInt()
        if (s.last() == needNum) {
            s.pop()
            sb.append("-\n")
        } else if (s.last() > needNum) {
            return "NO"
        } else {
            pushToNeedNumber(needNum)
        }
    }
    return sb.toString()
}

fun pushToNeedNumber(needNum: Int) {
    while (needNum != curNum) {
        s.push(++curNum)
        sb.append("+\n")
    }
    s.pop()
    sb.append("-\n")
}
