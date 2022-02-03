package hackerrank;

import java.util.List;

class Result {

    /*
     * Complete the 'jumpingOnClouds' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY c as parameter.
     */

    public static int jumpingOnClouds(List<Integer> c) {
        // Write your code here
        int[] jumpCount = new int[102];
        jumpCount[0] = 0;
        jumpCount[1] = 1;

        for (int i = 2; i < c.size(); ++i) {
            if (c.get(i) == 1) continue;
            if (c.get(i - 2) != 1) jumpCount[i] = jumpCount[i - 2] + 1;

            if (c.get(i - 1) != 1) {
                if (c.get(i - 2) != 1) jumpCount[i] = Math.min(jumpCount[i - 2] + 1, jumpCount[i - 1] + 1);
                else jumpCount[i] = jumpCount[i - 1] + 1;
            }
        }
        return jumpCount[c.size() - 1];
    }
}