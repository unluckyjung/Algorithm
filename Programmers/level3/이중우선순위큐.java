import java.util.TreeMap;

class Solution {
    TreeMap<Integer, Integer> nums = new TreeMap<>();

    public int[] solution(String[] operations) {
        for (String operator : operations) {
            String[] split = operator.split(" ");
            String cmd = split[0];
            int num = Integer.parseInt(split[1]);

            if ("I".equals(cmd)) {
                nums.put(num, nums.getOrDefault(num, 0) + 1);
            } else {
                delete(num);
            }
        }
        int[] answer = new int[2];

        if (!nums.isEmpty()) {
            answer[0] = nums.lastKey();
            answer[1] = nums.firstKey();
        }
        return answer;
    }

    private void delete(final int num) {
        if (nums.isEmpty()) return;

        if (num == -1) {
            int minValue = nums.firstKey();

            nums.put(minValue, nums.get(minValue) - 1);
            if (nums.get(minValue) == 0) nums.remove(minValue);
        } else {
            int maxValue = nums.lastKey();

            nums.put(maxValue, nums.get(maxValue) - 1);
            if (nums.get(maxValue) == 0) nums.remove(maxValue);
        }
    }
}