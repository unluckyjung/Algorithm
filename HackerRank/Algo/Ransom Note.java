package hackerrank;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Result {

    /*
     * Complete the 'checkMagazine' function below.
     *
     * The function accepts following parameters:
     *  1. STRING_ARRAY magazine
     *  2. STRING_ARRAY note
     */

    public static void checkMagazine(List<String> magazine, List<String> note) {
        // Write your code here
        Map<String, Integer> m = new HashMap<>();
        for (String word : magazine) {
            m.put(word, m.getOrDefault(word, 0) + 1);
        }

        for (String word : note) {
            if (!m.containsKey(word)) {
                System.out.println("No");
                return;
            } else {
                if (m.get(word) == 1) m.remove(word);
                else m.put(word, m.get(word) - 1);
            }
        }
        System.out.println("Yes");
    }

}
