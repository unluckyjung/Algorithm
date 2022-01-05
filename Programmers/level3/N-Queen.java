class Solution {

    boolean[][] visited = new boolean[3][24 + 2];
    int needQueenCount;
    int answer;

    public int solution(int n) {
        needQueenCount = n;
        dfs(0);
        return answer;
    }

    void dfs(int curQueenCount) {
        if (curQueenCount == needQueenCount) {
            answer++;
            return;
        }

        for (int i = 0; i < needQueenCount; ++i) {
            if (visited[0][i]) continue;
            if (visited[1][curQueenCount + i]) continue;
            if (visited[2][curQueenCount - i + needQueenCount]) continue;

            visited[0][i] = true;
            visited[1][curQueenCount + i] = true;
            visited[2][curQueenCount - i + needQueenCount] = true;

            dfs(curQueenCount + 1);

            visited[0][i] = false;
            visited[1][curQueenCount + i] = false;
            visited[2][curQueenCount - i + needQueenCount] = false;
        }
    }
}