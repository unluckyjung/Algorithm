import java.util.Stack;

class Solution {

    String[] priorityOrders = {"-+*", "-*+", "+*-", "+-*", "*-+", "*+-"};
    Stack<Long> numbers = new Stack<>();
    Stack<Character> opers = new Stack<>();
    long answer = 0;

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution("200-300-500-600*40+500+500"));
    }

    public long solution(String expression) {

        for (int i = 0; i < priorityOrders.length; ++i) {
            solve(priorityOrders[i], expression);
            numbers = new Stack<>();
        }
        return answer;
    }

    public void solve(final String priority, final String expression) {
        String num = "";
        for (int i = 0; i < expression.length(); ++i) {
            if (Character.isDigit(expression.charAt(i))) {
                num += expression.charAt(i);
            } else {
                numbers.add(Long.parseLong(num));
                num = "";
                operatorCalculate(expression.charAt(i), priority);
            }
        }
        if (num.length() != 0) {
            numbers.add(Long.parseLong(num));
        }

        while (!opers.empty()) {
            numberCalculate();
        }
        answer = Math.max(answer, Math.abs(numbers.pop()));
    }

    private void numberCalculate() {
        long num1 = numbers.pop();
        long num2 = numbers.pop();
        numbers.push(calculate(num2, num1, opers.pop()));
    }

    private void operatorCalculate(final char oper, final String priority) {
        if (oper == priority.charAt(0)) {
            while (!opers.empty() && opers.lastElement() == priority.charAt(0)) {
                numberCalculate();
            }
        } else if (oper == priority.charAt(1)) {
            while (!opers.empty() && (opers.lastElement() == priority.charAt(0) || opers.lastElement() == priority.charAt(1))) {
                numberCalculate();
            }
        } else {
            while (!opers.empty()) {
                numberCalculate();
            }
        }
        opers.add(oper);
    }

    private Long calculate(final long num1, final long num2, final char oper) {
        if (oper == '+') return num1 + num2;
        if (oper == '-') return num1 - num2;
        return num1 * num2;
    }
}
