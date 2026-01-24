fun solution(arr: IntArray): Int {
    val s = HashSet<Int>()
    for (num in arr) {
        s.add(num)
    }
    return s.size
}