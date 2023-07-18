import java.util.*

val cookiesLen = MutableList(1000002) { 0 }
var childCount = 0
var cookieCount = 0

fun main() {
    solve()
}

private fun solve() {
    var st = StringTokenizer(readln())
    childCount = st.nextToken().toInt()
    cookieCount = st.nextToken().toInt()
    var maxLen = 0
    var answer = 0

    st = StringTokenizer(readln())
    repeat(cookieCount) {
        cookiesLen[it] = st.nextToken().toInt()
        maxLen = maxOf(maxLen, cookiesLen[it])
    }
    if (cookieCount >= childCount) answer = 1

    var start = 0
    var end = maxLen
    var mid = 0

    while (start <= end) {
        mid = start + (end - start) / 2

        if (isCanDivideSize(divideSize = mid)) {
            answer = mid
            start = mid + 1
        } else {
            end = mid - 1
        }
    }
    println(answer)
}

fun isCanDivideSize(divideSize: Int): Boolean {
    if (divideSize == 0) return false
    var dividedCookieCount = 0

    repeat(cookieCount) {
        dividedCookieCount += cookiesLen[it] / divideSize
    }
    return dividedCookieCount >= childCount
}