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
     * Complete the 'makeAnagram' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING a
     *  2. STRING b
     */

    public static int makeAnagram(String a, String b) {
    // Write your code here
        int answer = 0;
        int[] str1Count = new int[27];
        int[] str2Count = new int[27];
        
        for(char ch : a.toCharArray()){
           str1Count[ch-'a']++; 
        }
        
        for(char ch : b.toCharArray()){
           str2Count[ch-'a']++; 
        }
        
        for(char ch = 'a'; ch <= 'z'; ++ch){
            if(str1Count[ch - 'a'] != str2Count[ch - 'a']) {
                answer += Math.abs(str1Count[ch - 'a'] - str2Count[ch - 'a']);
            }
        }
        return answer;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = bufferedReader.readLine();

        String b = bufferedReader.readLine();

        int res = Result.makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
