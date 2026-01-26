import java.util.*


fun solution(str: String): Int {
    val dq = ArrayDeque<Char>()
    val map = HashMap<Char, Char>()
    map[')'] = '('
    map[']'] = '['
    map['}'] = '{'

    for (bracket in str) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            dq.addLast(bracket)
            continue
        }
        if (dq.isEmpty()) return 0

        val candidate = dq.peekLast()
        if (candidate == map[bracket]) {
            dq.removeLast()
        } else return 0
    }

    return if (dq.isEmpty()) 1
    else 0
}
