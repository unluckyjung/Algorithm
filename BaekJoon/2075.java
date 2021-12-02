import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static PriorityQueue<Integer> pq = new PriorityQueue<>();
    private static StringTokenizer st;
    private static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int ii = 0; ii < n; ++ii) {
                int num = Integer.parseInt(st.nextToken());
                pq.offer(num);

                if (pq.size() > n) {
                    pq.poll();
                }
            }
        }

        System.out.println(pq.peek());
        br.close();
    }
}
