import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        Set<Integer> set = new TreeSet<>();
        for(int i = 0; i < numbers.length; ++i){
            for(int ii = i + 1; ii < numbers.length; ++ii){
                set.add(numbers[i] + numbers[ii]);
            }
        }

//        return set.stream().mapToInt(Integer::intValue).toArray();
        return getAnswer(new ArrayList<>(set));
    }

    private int[] getAnswer(final List<Integer> answerList) {
        int[] arr = new int[answerList.size()];
        for (int i = 0; i < answerList.size(); ++i) {
            arr[i] = answerList.get(i);
        }
        return arr;
    }
}