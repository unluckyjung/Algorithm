import java.util.*;

class Solution {
    Map<String, Set<String>> toReportMap = new HashMap<>();
    Map<String, Integer> reportedCount = new HashMap<>();
    Map<String, Map<String, Boolean>> isReported = new HashMap<>();
    List<String> banList = new ArrayList<>();


    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        for (String list : report) {
            String[] split = list.split(" ");
            String from = split[0];
            String to = split[1];

            Set<String> s = toReportMap.getOrDefault(from, new HashSet<>());
            s.add(to);
            toReportMap.put(from, s);

            if (isReported.containsKey(from) && isReported.get(from).containsKey(to)) continue;

            Map<String, Boolean> tmp = isReported.getOrDefault(from, new HashMap<>());
            tmp.put(to, true);
            isReported.put(from, tmp);
            reportedCount.put(to, reportedCount.getOrDefault(to, 0) + 1);
        }

        for (String id : reportedCount.keySet()) {
            if (reportedCount.get(id) >= k) {
                banList.add(id);
            }
        }

        for (int i = 0; i < id_list.length; ++i) {
            String id = id_list[i];

            for (String banId : banList) {
                Set<String> reportIds = toReportMap.getOrDefault(id, new HashSet<>());
                if (reportIds.contains(banId)) answer[i]++;
            }
        }
        return answer;
    }
}

//

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {

    public int[] solution(String[] id_list, String[] reports, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Integer> intId = new HashMap<>();

        Set<Integer>[] reportedCount = new HashSet[id_list.length];

        for (int i = 0; i < id_list.length; ++i) {
            reportedCount[i] = new HashSet<>();
            intId.put(id_list[i], i);
        }

        for (String report : reports) {
            String[] splited = report.split(" ");
            int from = intId.get(splited[0]);
            int to = intId.get(splited[1]);

            reportedCount[to].add(from);
        }

        for(int i = 0 ; i < id_list.length; ++i){
            if(reportedCount[i].size() < k) continue;
            for(int fromId : reportedCount[i]){
                answer[fromId]++;
            }
        }
        return answer;
    }
}