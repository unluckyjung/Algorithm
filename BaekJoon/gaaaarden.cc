#include <bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second
using namespace std;
struct planted {
    int xx, yy;
    int type;
};
int garden[52][52];
int dist[52][52];
queue<planted> q;
vector<pp> can_plant;
vector<int> plant_spot;
int n, m, G, R;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int lake = 0;
const int flower = 5;
int answer;
int bfs() {
    int flower_cnt = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (garden[cur.xx][cur.yy] == flower)continue;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.xx + dx[dir];
            int ny = cur.yy + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            int next_type = garden[nx][ny];
            if (next_type == lake or next_type == flower or next_type == cur.type)continue;
            if (next_type == 1 or next_type == 2) {
                garden[nx][ny] = cur.type;
                dist[nx][ny] = dist[cur.xx][cur.yy] + 1;
                q.push({ nx,ny,cur.type });
            }
            else {
                if (dist[nx][ny] != dist[cur.xx][cur.yy] + 1)continue;
                garden[nx][ny] = flower;
                flower_cnt++;
            }
        }
    }
    return flower_cnt;
}
void make_combi() {
    for (int G_seed = 0; G_seed < G; ++G_seed)
        plant_spot.push_back(4);
    for (int R_seed = 0; R_seed < R; ++R_seed)
        plant_spot.push_back(3);
    int left_spot_num = (int)can_plant.size() - G - R;
    for (int i = 0; i < left_spot_num; ++i)
        plant_spot.push_back(0);
}
void solve() {
    make_combi();
    int backup_garden[52][52];
    memcpy(backup_garden, garden, sizeof(garden));
    do {
        memset(dist, -1, sizeof(dist));
        for(int i = 0; i < (int)plant_spot.size(); ++i){
            if (plant_spot[i] == 4) {
                int nx = can_plant[i].x;
                int ny = can_plant[i].y;
                dist[nx][ny] = 0;
                garden[nx][ny] = 4;
                q.push({ nx,ny,4 });
            }
            else if (plant_spot[i] == 3) {
                int nx = can_plant[i].x;
                int ny = can_plant[i].y;
                dist[nx][ny] = 0;
                garden[nx][ny] = 3;
                q.push({ nx,ny,3 });
            }
        }
        answer = max(answer, bfs());
        memcpy(garden, backup_garden, sizeof(garden));
    } while (next_permutation(plant_spot.rbegin(), plant_spot.rend()));
    cout << answer << "\n";
}
void input() {
	cin >> n >> m >> G >> R;
	int spot;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> garden[i][ii];
			if (garden[i][ii] == 2) can_plant.push_back({ i,ii });
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    solve();
    return 0;
}