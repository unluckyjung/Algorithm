import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<Integer> solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();

        for (int[] cmd : commands) {
            int st = cmd[0] - 1;
            int ed = cmd[1] - 1;
            int target = cmd[2] -1;

            List<Integer> list = new ArrayList<>();
            for(int i = st; i <= ed; ++i){
                list.add(array[i]);
            }
            Collections.sort(list);
            answer.add(list.get(target));
        }

        return answer;
    }
}