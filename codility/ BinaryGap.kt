import kotlin.math.*

fun solution(n: Int): Int {
    fun toBinary(n: Int): String {
        val sb = StringBuilder()

        var num = n
        while (num > 0) {
            sb.append('0' + (num % 2))
            num /= 2
        }
        sb.append('1')

        return sb.reverse().toString()
    }
    if (n == 0) return 0

    val str = toBinary(n)

    var beforeIndex = -1
    var ans = 0
    for (i in 0 until str.length) {
        val ch = str[i]
        if (ch == '1') {
            if (beforeIndex != -1) {
                ans = max(ans, i - beforeIndex - 1)
            }
            beforeIndex = i
        }
    }
    return ans
}