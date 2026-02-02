import java.util.*

fun solution(str: String): Int {
    val stack = ArrayDeque<Char>()

    for (bracket in str) {
        if (bracket == '(') {
            stack.addLast(bracket)
        } else {
            if (stack.isEmpty() || stack.peekLast() != '(') return 0
            stack.removeLast()
        }
    }
    return if (stack.isEmpty()) 1 else 0
}