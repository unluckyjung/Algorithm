import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Result {

    /*
     * Complete the 'whatFlavors' function below.
     *
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY cost
     *  2. INTEGER money
     */

    public static void whatFlavors(List<Integer> costs, int money) {
        // Write your code here
        Map<Integer, Integer> costCount = new HashMap<>();
        for (int cost : costs) {
            costCount.put(cost, costCount.getOrDefault(cost, 0) + 1);
        }

        for (int i = 0; i < costs.size(); ++i) {
            int cost = costs.get(i);
            int needCost = money - cost;
            costCount.put(cost, costCount.get(cost) - 1);

            if (costCount.containsKey(needCost) && costCount.get(needCost) >= 1) {
                System.out.print(i + 1);
                for (int ii = i + 1; ii < costs.size(); ++ii) {
                    if (costs.get(ii) == needCost) {
                        System.out.println(String.format(" %d", ii + 1));
                        return;
                    }
                }
            }

            costCount.put(cost, costCount.get(cost) + 1);
        }
    }
}
