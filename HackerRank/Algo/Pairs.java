package hackerrank;

import java.util.Collections;
import java.util.List;

class Result {

    /*
     * Complete the 'pairs' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER k
     *  2. INTEGER_ARRAY arr
     */

    public static int pairs(int k, List<Integer> arr) {
    // Write your code here
                // Write your code here
        Collections.sort(arr);
        int answer = 0;

        for (int num : arr) {
            int targetNum = num - k;
            if (Collections.binarySearch(arr, targetNum) >= 0) answer++;
        }
        return answer;
    }
}
