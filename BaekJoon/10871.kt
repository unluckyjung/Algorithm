import java.util.*

fun main(){
    solve()
}

private fun solve(){
    val result = StringBuilder()

    var line = StringTokenizer(readln())
    val n = line.nextToken().toInt()
    val pivotNum = line.nextToken().toInt()
    line = StringTokenizer(readln())

    repeat(n){
        val num = line.nextToken().toInt()
        if(num < pivotNum) result.append("$num ")
    }
    println(result)
}