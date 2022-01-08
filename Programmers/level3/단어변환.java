import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    int answer = Integer.MAX_VALUE;
    List<String> words = new ArrayList<>();
    boolean[] isUsed = new boolean[52];

    public int solution(String begin, String target, String[] wordss) {
        words = Arrays.stream(wordss).collect(Collectors.toList());

        dfs(begin, target, 0);

        if (answer == Integer.MAX_VALUE) return 0;
        return answer;
    }

    private void dfs(final String curWord, final String target, final int count) {
        if (curWord.equals(target)) {
            answer = Math.min(answer, count);
            return;
        }

        for (int i = 0; i < words.size(); ++i) {
            if (isUsed[i]) continue;
            if (isOnlyOneDiff(curWord, words.get(i))) {
                isUsed[i] = true;
                dfs(words.get(i), target, count + 1);
                isUsed[i] = false;
            }
        }
    }

    private boolean isOnlyOneDiff(final String curWord, final String nextWord) {
        int diffCount = 0;
        for (int i = 0; i < curWord.length(); ++i) {
            if (curWord.charAt(i) != nextWord.charAt(i)) diffCount++;
        }
        return diffCount == 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] inputWords = {
                "hot", "dot", "dog", "lot", "log", "cog"
        };
        System.out.println(solution.solution("hit", "cog", inputWords));
    }
}
