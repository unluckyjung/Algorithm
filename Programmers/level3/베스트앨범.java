import java.util.*;

class Solution {

    List<Integer> answer = new ArrayList<>();
    Map<String, Integer> typeMap = new HashMap<>();
    Map<String, List<Pair>> playMap = new TreeMap<>();

    public List<Integer> solution(String[] genres, int[] plays) {
        for (int i = 0; i < genres.length; ++i) {
            String type = genres[i];
            int playIndex = i;
            int playCount = plays[i];

            if (typeMap.containsKey(type)) typeMap.put(type, typeMap.get(type) + playCount);
            else typeMap.put(type, playCount);

            if (playMap.containsKey(type)) {
                List<Pair> list = playMap.get(type);
                list.add(new Pair(playCount, playIndex));

                playMap.put(type, list);
            } else {
                playMap.put(type, new ArrayList<>(Arrays.asList(new Pair(playCount, playIndex))));
            }
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
