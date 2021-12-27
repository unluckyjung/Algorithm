class Solution {

    public int solution(int[] numbers) {
        int answer = 0;
        boolean[] used = new boolean[10];

        for (int num : numbers) {
            used[num] = true;
        }

        for (int num = 0; num <= 9; ++num) {
            if (used[num]) continue;
            answer += num;
        }

        return answer;
    }
}