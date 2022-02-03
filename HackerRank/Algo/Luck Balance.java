import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Result {

    public static int luckBalance(int k, List<List<Integer>> contests) {
        int luckSum = 0;

        List<Integer> importantContests = new ArrayList<>();

        for (List<Integer> contest : contests) {
            if (contest.get(1) == 0) luckSum += contest.get(0);
            else importantContests.add(contest.get(0));
        }

        Collections.sort(importantContests, Comparator.reverseOrder());

        for (Integer luckScore : importantContests) {
            if (k > 0) {
                luckSum += luckScore;
                k--;
            } else {
                luckSum -= luckScore;
            }
        }

        return luckSum;
    }
}