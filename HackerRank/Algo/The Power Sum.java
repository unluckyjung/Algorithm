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
     * Complete the 'powerSum' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER X
     *  2. INTEGER N
     */

    
    public static int powerSum(int X, int N) {
    // Write your code here
        // {0 ~ 33}
        int[] dp = new int[1002];
        dp[0] = 1;
        
        for(int i = 1; i <= 33; ++i){
            int powNum = (int)Math.pow(i, N);
            for(int ii = X ; ii >= powNum; --ii){
                dp[ii] += dp[ii - powNum];
            }
        }
        
        return dp[X];
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int X = Integer.parseInt(bufferedReader.readLine().trim());

        int N = Integer.parseInt(bufferedReader.readLine().trim());

        int result = Result.powerSum(X, N);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
