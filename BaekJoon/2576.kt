import java.util.*

fun main() {
    solve()
}

private fun solve() {
    val odds = PriorityQueue<Int>()
    repeat(7){
        val num = readln().toInt()
        if(num % 2 != 0) odds.add(num)
    }
    if(odds.isEmpty()) {
        println("-1")
    } else{
        println(odds.sum())
        println(odds.element())
    }
}

private fun solve() {
    var sum = 0
    var minOdd = Int.MAX_VALUE
    
    repeat(7){
        val num = readln().toInt()
        if(num % 2 != 0) {
            sum += num
            minOdd = minOf(minOdd, num)
        }
    }
    if(sum == 0) {
        println("-1")
    } else{
        println(sum)
        println(minOdd)
    }
}