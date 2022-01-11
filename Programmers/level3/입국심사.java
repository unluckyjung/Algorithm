import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    List<Integer> times;

    public long solution(int n, int[] timess) {
        times = Arrays.stream(timess).boxed().collect(Collectors.toList());
        Collections.sort(times);

        long answer = 0;
        long st = 1;
        long ed = (long) n * times.get(times.size() - 1);

        while (st <= ed) {
            long mid = st + (ed - st) / 2;
            if (isCan(n, mid)) {
                answer = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return answer;
    }

    private boolean isCan(final int targetCount, final long candidateTime) {
        long solHumanCount = 0;
        for (int speed : times) {
            solHumanCount += candidateTime / speed;
        }
        return solHumanCount >= targetCount;
    }
}