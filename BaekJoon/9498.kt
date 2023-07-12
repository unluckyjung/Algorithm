fun main() {
    solve()
}

enum class Score(grade: String) {
    A("A"),
    B("B"),
    C("C"),
    D("D"),
    F("F");

    companion object {
        fun calculate(score: Int): Score {
            return if (score in 90..100) A
            else if (score >= 80) B
            else if (score >= 70) C
            else if (score >= 60) D
            else F
        }
    }
}

private fun solve() {
    val num = readln().toInt()
    println(Score.calculate(num))
}
