fun solution(st: Int, ed: Int, jmp: Int): Int {
    val diff = ed - st
    var answer = diff / jmp

    if (diff % jmp != 0) answer++
    return answer
}