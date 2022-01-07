class Solution {
    int answer = 0;

    public int solution(int left, int right) {
        for (int num = left; num <= right; ++num) {
            int cnt = 0;

            for (int candiateNum = 1; candiateNum <= num; ++candiateNum) {
                if (num % candiateNum == 0) cnt++;
            }
            if (cnt % 2 == 0) answer += num;
            else answer -= num;
        }
        return answer;
    }
}