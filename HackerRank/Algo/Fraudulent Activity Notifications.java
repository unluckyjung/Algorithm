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
     * Complete the 'activityNotifications' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY expenditure
     *  2. INTEGER d
     */
    static int[] numVisitedCount = new int[202];

    public static int activityNotifications(List<Integer> expenditure, int d) {
        int answer = 0;

        if(expenditure.size() == d) return answer;
        
        for(int i = 0; i < d; ++i){
            int num = expenditure.get(i);
            numVisitedCount[num]++;
        }
        
        int mid = getMidNum(d);
        int fee = expenditure.get(d);
        if (fee >= mid) answer++;
        
        for(int startIndex = 1 ; startIndex <= expenditure.size() - d - 1; ++startIndex){
            int beforeNum = expenditure.get(startIndex - 1);
            numVisitedCount[beforeNum]--;
            
            int newNum = expenditure.get(startIndex + d - 1);
            numVisitedCount[newNum]++;
            
            mid = getMidNum(d);
            fee = expenditure.get(startIndex + d);
            if (fee >= mid) answer++;
        }
        return answer;
    }
    
    
    private static int getMidNum(int d){
        int visitedSum = 0;
        
        // 짝수
        if(d % 2 == 0){
            int num1 = -1;
            
            for(int i = 0; i <= 200; ++i){
                visitedSum += numVisitedCount[i];
                
                if(visitedSum == d / 2) num1 = i;
                if(visitedSum > (d / 2) && num1 == -1) return i * 2;
                if(visitedSum > (d / 2) && num1 != -1) return num1 + i;
            }
        }
        
        // 홀수
        for(int i = 0; i <= 200; ++i){
            visitedSum += numVisitedCount[i];
            if(visitedSum > d / 2) return i * 2;
        }
        
        return 200;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int d = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> expenditure = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
