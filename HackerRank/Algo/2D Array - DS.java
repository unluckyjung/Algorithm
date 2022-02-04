package hackerrank;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import static java.util.stream.Collectors.toList;

class Result {

    static int[][] hourglasses = {
            {0, 0}, {0, 1}, {0, 2},
            {1, 1},
            {2, 0}, {2, 1}, {2, 2}
    };

    public static int hourglassSum(List<List<Integer>> arr) {
        int answer = Integer.MIN_VALUE;
        for (int i = 0; i <= arr.size() - 3; ++i) {
            for (int ii = 0; ii <= arr.get(0).size() - 3; ++ii) {
                answer = Math.max(answer, patternSum(i, ii, arr));
            }
        }

        return answer;
    }

    private static int patternSum(final int n, final int m, final List<List<Integer>> arr) {
        int sum = 0;
        for (int i = 0; i < 7; ++i) {
            int nxtX = hourglasses[i][0] + n;
            int nxtY = hourglasses[i][1] + m;
            sum += arr.get(nxtX).get(nxtY);
        }
        return sum;
    }
}