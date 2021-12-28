package programmers;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

    final int[] dx = {-1, 1, 0, 0};
    final int[] dy = {0, 0, -1, 1};

    String[] board;
    int[] answer = new int[5];

    public int[] solution(String[][] places) {
        for (int i = 0; i < 5; ++i) {
            board = places[i];
            if (isCan()) answer[i] = 1;
            else answer[i] = 0;
        }
        return answer;
    }

    private boolean isCan() {
        for (int i = 0; i < 5; ++i) {
            for (int ii = 0; ii < 5; ++ii) {
                if (board[i].charAt(ii) != 'P') continue;
                if (isValidateHuman(i, ii)) continue;
                return false;
            }
        }
        return true;
    }

    private boolean isValidateHuman(final int startX, final int startY) {
        boolean[][] visited = new boolean[5][5];
        Queue<Pair> q = new LinkedList<>();
        visited[startX][startY] = true;
        q.add(new Pair(startX, startY));

        int checkedDist = 0;
        while (!q.isEmpty()) {
            if (checkedDist == 3) return true;
            int qSize = q.size();

            while (qSize-- > 0) {
                Pair cur = q.remove();
                if (board[cur.x].charAt(cur.y) == 'P') {
                    if (checkedDist > 0 && checkedDist <= 2) return false;
                }

                for (int dir = 0; dir < 4; ++dir) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];

                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (visited[nx][ny]) continue;
                    if (board[nx].charAt(ny) == 'X') continue;

                    visited[nx][ny] = true;
                    q.add(new Pair(nx, ny));
                }
            }
            checkedDist++;
        }
        return true;
    }
}

class Pair {
    int x;
    int y;

    public Pair(final int x, final int y) {
        this.x = x;
        this.y = y;
    }
}