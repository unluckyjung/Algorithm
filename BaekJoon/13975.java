import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder result = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int tryCount;
        tryCount = Integer.parseInt(br.readLine());
        for (int i = 0; i < tryCount; ++i) {
            solve();
        }
        System.out.print(result);
        br.close();
    }

    private static void solve() throws IOException {
        int bookPageCount = Integer.parseInt(br.readLine());
        long cost = 0L;
        StringTokenizer st = new StringTokenizer(br.readLine());
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int i = 0; i < bookPageCount; ++i) {
            pq.add(Long.parseLong(st.nextToken()));
        }

        while (pq.size() >= 2) {
            long page1 = pq.remove();
            long page2 = pq.remove();
            cost += page1 + page2;
            pq.add(page1 + page2);
        }

        result.append(cost).append("\n");
    }
}
