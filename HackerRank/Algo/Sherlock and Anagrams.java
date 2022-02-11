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
     * Complete the 'sherlockAndAnagrams' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING s as parameter.
     */

    public static int sherlockAndAnagrams(String s) {
        int answer = 0;
        // Write your code here
        for(int subStrLen = 1; subStrLen < s.length(); ++subStrLen){
            for(int i = 0 ; i + subStrLen < s.length(); ++ i){
                answer += getAnagramCount(i, subStrLen, s);
            }
        }
        return answer;
    }
    
    private static int getAnagramCount(int startIndex, int subStrLen, String s){
        int[] alphaCount = new int['z' - 'a' + 1];
        int ret = 0;
        
        // basic subStr
        for(int i = 0; i < subStrLen; ++i){
            char ch = s.charAt(startIndex + i);
            alphaCount[ch - 'a']++;
        }
        
        // other subStr
        for(int i = startIndex + 1; i + subStrLen <= s.length(); ++i){
            int[]alphaCount2 = new int['z' - 'a' + 1];
            for(int ii = 0; ii < subStrLen; ++ii){
                char ch = s.charAt(i + ii);
                alphaCount2[ch - 'a']++;
            }
            
            if(isSameCount(alphaCount, alphaCount2)) ret++;
        }
        return ret;
    }
    
    private static boolean isSameCount(int[] alphaCount1, int[] alphaCount2){
        for(int al = 0; al <= 'z' - 'a'; ++al){
            if(alphaCount1[al] != alphaCount2[al]) return false;
        }
        return true;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String s = bufferedReader.readLine();

                int result = Result.sherlockAndAnagrams(s);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
