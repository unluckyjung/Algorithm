import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    public static Deque<Pair> window = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int numCount = Integer.parseInt(st.nextToken());
        int windowSizeLimit = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int index = 0; index < numCount; ++index) {
            int num = Integer.parseInt(st.nextToken());
            pushToWindow(index, num);
            eraseRangeOutIndex(index - windowSizeLimit);
            int minNumber = getMinValueInWindow();
            bw.append(minNumber + " ");
        }
        bw.flush();

        br.close();
        bw.close();
    }

    public static void pushToWindow(int index, int num) {
        while (!window.isEmpty() && window.getLast().getNumber() >= num) {
            window.pollLast();
        }
        window.addLast(new Pair(index, num));
    }

    public static void eraseRangeOutIndex(int minValidIndex) {
        if(!isValidIndex(window.getFirst().getIndex(), minValidIndex)){
            window.pollFirst();
        }
    }

    public static boolean isValidIndex(int windowFrontIndex, int minValidIndex) {
        return windowFrontIndex > minValidIndex;
    }

    public static int getMinValueInWindow(){
        return window.getFirst().getNumber();
    }
}

class Pair {
    private int index;
    private int number;

    Pair(int index, int number) {
        this.index = index;
        this.number = number;
    }

    public int getIndex() {
        return index;
    }

    public int getNumber() {
        return number;
    }
}