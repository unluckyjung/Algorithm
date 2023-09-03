import java.util.*

val sb = StringBuilder()
var t = 0

fun main() {
    t = readln().toInt()
    repeat(t) {
        val str = readln()
        solve(str)
    }
    println(sb)
}

fun solve(str: String) {
    val list = LinkedList<Char>()
    val iter = list.listIterator()

    str.forEach {
        when (it) {
            '<' -> {
                if (iter.hasPrevious()) {
                    iter.previous()
                }
            }
            '>' -> {
                if (iter.hasNext()) {
                    iter.next()
                }
            }
            '-' -> {
                if (iter.hasPrevious()) {
                    iter.previous()
                    iter.remove()
                }
            }
            else -> {
                iter.add(it)
            }
        }
    }

    list.forEach {
        sb.append(it)
    }
    sb.append("\n")
}