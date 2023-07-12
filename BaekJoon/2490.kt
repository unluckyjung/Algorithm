val result = StringBuilder()

fun main() {
    solve()
}


private fun solve() {

    repeat(3){
        var sum = 0
        val nums = readln().split(" ").map { it.toInt() }
        nums.forEach {
            sum += it
        }
        when(sum){
            4 -> result.append("E\n")
            0 -> result.append("D\n")
            1 -> result.append("C\n")
            2 -> result.append("B\n")
            3 -> result.append("A\n")
        }
    }
    println(result)
}