#include <bits/stdc++.h>
using namespace std;

struct spot {
    int lost_money;
    int x, y;
};

struct cmp {
    bool operator()(const spot &s1, const spot &s2){
        return s1.lost_money > s2.lost_money;
    }
};

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int board[127][127];
bool visit[127][127];
int n;

void Init() {
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
        }
    }
}

int Dijkstra() {
    priority_queue<spot, vector<spot>, cmp> pq;

    visit[0][0] = true;
    pq.push({ board[0][0],0,0 });

    while (!pq.empty()) {
        auto cur = pq.top();    pq.pop();
        if (cur.x == n - 1 and cur.y == n - 1) return cur.lost_money;
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
            if (visit[nx][ny]) continue;
            visit[nx][ny] = true;
            
            int cost = board[nx][ny];
            pq.push({ cur.lost_money + cost, nx,ny });
        }
    }
    return -1;
}

int Solve() {
    return Dijkstra();
}

void Input() {
    int cnt = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;

        Init();
        cout << "Problem " << cnt << ": " << Solve() << "\n";
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();

    return 0;
}