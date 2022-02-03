import java.util.Comparator;
import java.util.PriorityQueue;

class Result {

    static int getMinimumCost(int humanCount, int[] prices) {
        int answer = 0;
        int allMemberBuyCount = prices.length / humanCount;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        for (int price : prices) {
            pq.add(price);
        }

        for (int i = 1; i <= allMemberBuyCount; ++i) {
            for(int ii = 0; ii < humanCount; ++ii) {
                answer += pq.remove() * i;
            }
        }

        while (!pq.isEmpty()) {
            answer += pq.remove() * (allMemberBuyCount + 1);
        }

        return answer;
    }
}