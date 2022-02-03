import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

class Result {

    public static int maxMin(int k, List<Integer> arr) {
        Deque<Integer> deque = new LinkedList<>();

        Collections.sort(arr);

        int answer = Integer.MAX_VALUE;
        for (int num : arr) {
            deque.add(num);
            if (deque.size() == k) {
                answer = Math.min(answer, deque.getLast() - deque.getFirst());
                deque.removeFirst();
            }
        }
        return answer;
    }
}