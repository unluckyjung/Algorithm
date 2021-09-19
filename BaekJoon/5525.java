import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int needChainIOICount;
    private static int inputStringLen;
    private static String inputString;

    public static void main(String[] args) throws IOException {
        needChainIOICount = Integer.parseInt(br.readLine());
        inputStringLen = Integer.parseInt(br.readLine());
        inputString = br.readLine();
        br.close();

        solution();
    }

    private static void solution() {
        int answer = 0;
        int chainCount = 0;
        for (int i = 1; i < inputStringLen - 1; ) {
            if (inputString.charAt(i - 1) == 'I' && inputString.charAt(i) == 'O' && inputString.charAt(i + 1) == 'I') {
                chainCount++;
                if (chainCount == needChainIOICount) {
                    answer++;
                    chainCount--;
                }
                i += 2;
            } else {
                chainCount = 0;
                i++;
            }
        }
        System.out.println(answer);
    }
}