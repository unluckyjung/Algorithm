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
     * Complete the 'isValid' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */


    public static String isValid(String s) {
        int[] charCount = new int[27];

        Set<Character> chs = new HashSet<>();

        for (char ch : s.toCharArray()) {
            charCount[ch - 'a']++;
            chs.add(ch);
        }

        if (isAllSame(charCount, s, chs)) return "YES";

        for (char ch : chs) {
            charCount[ch - 'a']--;
            if (isAllSame(charCount, s, chs)) return "YES";
            charCount[ch - 'a']++;
        }

        return "NO";
    }

    private static boolean isAllSame(final int[] charCount, final String str, final Set<Character> chs) {
        int baseCount = charCount[str.charAt(0) - 'a'];

        for (char ch : chs) {
            if (charCount[ch - 'a'] == 0) continue;
            if (baseCount != charCount[ch - 'a']) return false;
        }
        return true;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.isValid(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
