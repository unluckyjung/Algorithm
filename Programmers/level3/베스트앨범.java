import java.util.*;

class Solution {

    List<Integer> answer = new ArrayList<>();
    Map<String, Integer> typeMap = new HashMap<>();
    Map<String, List<Pair>> playMap = new HashMap<>();

    public List<Integer> solution(String[] genres, int[] plays) {
        for (int i = 0; i < genres.length; ++i) {
            String type = genres[i];
            int playIndex = i;
            int playCount = plays[i];

            typeMap.put(type, typeMap.getOrDefault(type, 0) + playCount);

            List<Pair> list = playMap.getOrDefault(type, new ArrayList<>());
            list.add(new Pair(playCount, playIndex));
            playMap.put(type, list);
        }

        Map<Integer, String> orderedTypes = new TreeMap<>();
        for (String type : typeMap.keySet()) {
            orderedTypes.put(-typeMap.get(type), type);
        }

        for (Integer playCount : orderedTypes.keySet()) {
            String type = orderedTypes.get(playCount);
            List<Pair> list = playMap.get(type);
            Collections.sort(list);

            for (int i = 0; i < list.size() && i < 2; ++i) {
                answer.add(list.get(i).number);
            }
        }
        return answer;
    }
}

class Pair implements Comparable<Pair> {
    int playCount;
    int number;

    public Pair(final int playCount, final int number) {
        this.playCount = playCount;
        this.number = number;
    }

    @Override
    public int compareTo(final Pair o) {
        if (this.playCount == o.playCount) {
            return Integer.compare(this.number, o.number);
        } else {
            return -Integer.compare(this.playCount, o.playCount);
        }
    }
}
