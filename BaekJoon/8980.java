import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int townCount;
    static int truckCapacity;
    static int answer;
    static int[] truckWeight = new int[2002];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        townCount = Integer.parseInt(st.nextToken());
        truckCapacity = Integer.parseInt(st.nextToken());

        int n = Integer.parseInt(br.readLine());
        List<Load> loads = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            loads.add(new Load(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(loads);
        delivery(loads);
        System.out.println(answer);
    }

    private static void delivery(final List<Load> loads) {
        for (Load load : loads) {
            int alreadyLoadCount = 0;
            for (int spot = load.from; spot < load.to; ++spot) {
                alreadyLoadCount = Math.max(alreadyLoadCount, truckWeight[spot]);
            }

            int canLoadCount = Math.min(load.boxCount, truckCapacity - alreadyLoadCount);
            answer += canLoadCount;

            for (int spot = load.from; spot < load.to; ++spot) {
                truckWeight[spot] += canLoadCount;
            }
        }
    }
}

class Load implements Comparable<Load> {
    int from;
    int to;
    int boxCount;

    public Load(final int from, final int to, final int boxCount) {
        this.from = from;
        this.to = to;
        this.boxCount = boxCount;
    }

    @Override
    public int compareTo(final Load o) {
        if (to == o.to) {
            return Integer.compare(from, o.from);
        }
        return Integer.compare(to, o.to);
    }
}