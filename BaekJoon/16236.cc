#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

bool visit[22][22];
int water[22][22];

vector<pp> fish_vec;


int n;
int shark_size = 2;
int _time, ate_fish_cnt;
int shark_x, shark_y;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

void Init() {
    fish_vec.clear();
    memset(visit, false, sizeof(visit));
}

void eat_fish() {
    sort(fish_vec.begin(), fish_vec.end());

    int fx = fish_vec[0].x;
    int fy = fish_vec[0].y;

    water[fx][fy] = 0;
    shark_x = fx;
    shark_y = fy;

    ate_fish_cnt++;


    if (ate_fish_cnt == shark_size) {
        shark_size++;
        ate_fish_cnt = 0;
    }

}

bool is_ate() {
    int dist = 0;
    bool ate = false;

    queue<pp> q;

    visit[shark_x][shark_y] = true;
    q.push({ shark_x,shark_y });

    while (!q.empty()) {
        int q_size = q.size();
        dist++;

		while (q_size--) {
            auto cur = q.front(); q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                if (visit[nx][ny]) continue;
                if (water[nx][ny] > shark_size) continue;

                visit[nx][ny] = true;
                q.push({ nx,ny });

                if (shark_size == water[nx][ny] or water[nx][ny] == 0)continue;
                fish_vec.push_back({ nx,ny });
                ate = true;
            }
		}
        if (ate) {
            _time += dist;
            return true;
        }
    }


    return false;
}

int solve() {
    while (1) {
        if (!is_ate())   return _time;
        eat_fish();
        Init();
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> water[i][ii];
            if (water[i][ii] == 9) {
                water[i][ii] = 0;
                shark_x = i;
                shark_y = ii;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    input();
    cout << solve() << "\n";


    return 0;
}