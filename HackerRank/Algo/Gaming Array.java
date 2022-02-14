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

class Result {

    /*
     * Complete the 'gamingArray' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static String gamingArray(List<Integer> arr) {
    // Write your code here
        // bob first
        // greater = countup
        
        // 1 3 5 7 9
        // b a b a b
        
        // 5 2 6 3 4
        // b b a a a
        int count = 0;
        int maxValue = arr.get(0);
        for(int num : arr){
            if(num > maxValue) {
                maxValue = num;
                count++;
            }
        }

        
        if(count % 2 == 0) return "BOB";
        else return "ANDY";
    }


    public static String gamingArray2(List<Integer> arr) {

        int count = -1;
        
        Stack<Pair> s = new Stack<>();
        
        for(int num : arr){
            if(s.empty()) {
                s.push(new Pair(num, num));
                continue;
            }
            
            s.push(new Pair(Math.max(num, s.lastElement().maxValue), num));
        }
        
        while(!s.empty()){
            while(s.lastElement().maxValue != s.lastElement().value){
                s.pop();
            }
            s.pop();
            count++;
        }
        
        if(count % 2 == 0) return "BOB";
        else return "ANDY";
    }

}

class Pair{
    int maxValue;
    int value;
    public Pair(int maxValue, int value){
        this.maxValue = maxValue;
        this.value = value;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int g = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, g).forEach(gItr -> {
            try {
                int arrCount = Integer.parseInt(bufferedReader.readLine().trim());

                List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                    .map(Integer::parseInt)
                    .collect(toList());

                String result = Result.gamingArray(arr);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
