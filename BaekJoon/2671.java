import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        if (br.readLine().matches("(100+1+|01)+")) {
            System.out.println("SUBMARINE\n");
        } else {
            System.out.println("NOISE\n");
        }
        br.close();
    }
}