#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

vector<vector<int>> board;
bool visit[102][102];

int n, m;
queue<pp> q;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int bfs() {
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        auto cur = q.front(); q.pop();
        const int color = board[cur.x][cur.y];
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (visit[nx][ny])continue;
            if (board[nx][ny] != color)continue;
            
            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    return cnt;
}

vector<int> solution(int mm, int nn, vector<vector<int>> picture) {
    vector<int> answer;
    
    memset(visit, false, sizeof(visit));
    int area_cnt = 0 , MAX_area = 0;

    board = picture;
    n = mm, m = nn;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == 0)continue;
            if (visit[i][ii])continue;
            area_cnt++;
            visit[i][ii] = true;
            q.push({ i,ii });
            MAX_area = max(MAX_area, bfs());
        }
    }

    answer.push_back(area_cnt);
    answer.push_back(MAX_area);

    return answer;
}


void input() {
    vector<int> ret = solution(6, 4, vector<vector<int>>{{1, 1, 1, 0}
        ,{1, 2, 2, 0}
        ,{1, 0, 0, 1}
        ,{0, 0, 0, 1}
        ,{0, 0, 0, 3}
        ,{0, 0, 0, 3} });

    cout << ret[0] << " " << ret[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}