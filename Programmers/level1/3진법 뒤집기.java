package programmers;

class Solution {
    public int solution(int n) {
        StringBuilder nums = new StringBuilder();

        while (n != 0) {
            nums.append(n % 3);
            n /= 3;
        }

        return Integer.parseInt(nums.toString(), 3);
    }

    public int solution2(int n) {
        int answer = 0;
        StringBuilder nums = new StringBuilder();

        while (n != 0) {
            nums.append(n % 3);
            n /= 3;
        }

        nums.reverse();
        int pivot = 1;

        for(char num : nums.toString().toCharArray()){
            answer += (num - '0') * pivot;
            pivot *= 3;
        }
        return answer;
    }
}