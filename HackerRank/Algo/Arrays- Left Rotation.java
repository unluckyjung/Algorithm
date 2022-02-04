package hackerrank;

import java.util.Collections;
import java.util.List;

class Result {

    public static List<Integer> rotLeft(List<Integer> a, int d) {
        // Write your code here

        Collections.reverse(a);
        Collections.reverse(a.subList(0, a.size() - d));
        Collections.reverse(a.subList(a.size() - d, a.size()));

        return a;
    }
}
