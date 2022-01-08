import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> times = new Stack<>();

        for (int time = 0; time < prices.length; ++time) {
            int curCost = prices[time];
            int curTime = time;

            while (!times.isEmpty() && curCost < prices[times.lastElement()]) {
                answer[times.lastElement()] = curTime - times.pop();
            }
            times.push(curTime);
        }
        int lastTime = prices.length - 1;

        while (!times.isEmpty()) {
            answer[times.lastElement()] = lastTime - times.pop();
        }
        return answer;
    }
}