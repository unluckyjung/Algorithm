fun solution(arr: IntArray): Int {
    arr.sort()

    for (i in 1 until arr.size step 2) {
        if (arr[i - 1] != arr[i]) return arr[i - 1]
    }

    return arr[arr.size - 1]
}


fun solution2(arr: IntArray): Int {
    // Implement your solution here
    val numMap = HashMap<Int, Int>()

    for (num in arr) {
        numMap[num] = (numMap[num] ?: 0) + 1
    }

    for ((num, count) in numMap) {
        if (count % 2 != 0) return num
    }
    return -1
}