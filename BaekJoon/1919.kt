import kotlin.math.abs

fun main() {
    val str1 = readln()
    val str2 = readln()

    val str1Map = mutableMapOf<Char, Int>()
    val str2Map = mutableMapOf<Char, Int>()
    val existChars = mutableSetOf<Char>()

    str1.forEach {
        str1Map[it] = str1Map.getOrDefault(it, 0) + 1
        existChars.add(it)
    }

    str2.forEach {
        str2Map[it] = str2Map.getOrDefault(it, 0) + 1
        existChars.add(it)
    }

    var answer = 0
    existChars.forEach {
        answer += abs(str1Map.getOrDefault(it, 0) - str2Map.getOrDefault(it, 0))
    }

    println(answer)
}
