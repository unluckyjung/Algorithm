import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the freqQuery function below.
    static List<Integer> freqQuery(List<List<Integer>> queries) {
        Map<Integer, Integer> numCount = new HashMap<>();
        Map<Integer, Integer> frequencyCount = new HashMap<>();
        List<Integer> answer = new ArrayList<>();

        for (List<Integer> query : queries) {
            int cmd = query.get(0);
            int num = query.get(1);

            if (cmd == 1) {
                numCount.put(num, numCount.getOrDefault(num, 0) + 1);

                int frequency = numCount.get(num);
                frequencyCount.put(frequency, frequencyCount.getOrDefault(frequency, 0) + 1);
                frequencyCount.put(frequency - 1, frequencyCount.getOrDefault(frequency - 1, 0) - 1);

            } else if (cmd == 2) {
                if (numCount.containsKey(num) && numCount.get(num) >= 1) {
                    numCount.put(num, numCount.get(num) - 1);
                    int frequency = numCount.get(num);

                    frequencyCount.put(frequency, frequencyCount.getOrDefault(frequency, 0) + 1);
                    frequencyCount.put(frequency + 1, frequencyCount.getOrDefault(frequency + 1, 0) - 1);
                }
            } else {
                if (frequencyCount.getOrDefault(num, 0) >= 1) {
                    answer.add(1);
                } else {
                    answer.add(0);
                }
            }
        }
        return answer;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> ans = freqQuery(queries);

        bufferedWriter.write(
            ans.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
