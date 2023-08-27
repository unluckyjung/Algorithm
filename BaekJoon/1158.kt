import java.util.*

val sb = StringBuilder()
val q = LinkedList<Int>()

fun main() {
    val st = StringTokenizer(readln())
    val numCount = st.nextToken().toInt()
    val splitCount = st.nextToken().toInt()

    repeat(numCount) {
        q.add(it + 1)
    }

    sb.append("<")
    while (q.isEmpty().not()) {
        repeat(splitCount - 1) {
            q.add(q.pop())
        }
        sb.append(q.pop())
        if (q.isEmpty().not()) sb.append(", ")
    }
    sb.append(">")
    println(sb)
}
