#include<bits/stdc++.h>
using namespace std;

char board[1501][1501];
bool visit[1501][1501];
bool w_visit[1501][1501];



int w_time[1501][1501];
bool w_used[1501][1501];




int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
int cnt;

int L_x, L_y;
bool find_L;


queue<tuple<int, int, int>> wq;
//x, y , cnt;

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string line;    cin >> line;
        for (int ii = 0; ii < m; ++ii) {
            board[i][ii] = line[ii];
            if (board[i][ii] == '.'){
                w_visit[i][ii] =true;
                wq.push({i,ii,0});
            }
            if (!find_L && board[i][ii] == 'L') {
                L_x = i;
                L_y = ii;
                find_L = true;
            }
        }
    }
}

void output() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cout << board[i][ii];
        }
        cout << "\n";
    }
}


void can_go() {
    queue<pair<int, int > > q;
    memset(visit, false, sizeof(visit));
    visit[L_x][L_y] = true;
    q.push({ L_x, L_y });

    while (!q.empty()) {
        auto cur = q.front();   q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;

        if (cur_x != L_x and cur_y != L_y and board[cur_x][cur_y] == 'L') {
            cout << cnt << "\n";
            exit(0);
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (visit[nx][ny])continue;
            if (board[nx][ny] == 'X')continue;

            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

// void sink() {
//     cnt++;

//     for (int i = 0; i < n; ++i) {
//         for (int ii = 0; ii < m; ++ii) {
//             if (w_used[i][ii])  continue;
//             if (board[i][ii] == '.') {
//                 if (w_time[i][ii] > cnt)continue;
//                 w_used[i][ii] = true;
//                 //w_visit[i][ii] = cnt;

//                 for (int dir = 0; dir < 4; ++dir) {
//                     int nx = i + dx[dir];
//                     int ny = ii + dy[dir];

//                     if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
//                     if (w_used[nx][ny]) continue;
//                     if (w_time[nx][ny] >= cnt)continue;
//                     if (board[nx][ny] != 'X')continue;
//                     w_time[nx][ny] = cnt+1;

//                     board[nx][ny] = '.';
//                 }
//             }
//         }
//     }

// }


void sink_2(){
    while(!wq.empty()){
        auto cur = wq.front();
        if(get<2>(cur) > cnt) {
            cnt++;
            return;
        }
        wq.pop();

        for(int dir = 0 ; dir<4; ++dir){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (w_visit[nx][ny])continue;
            if (board[nx][ny] != 'X')continue;

            w_visit[nx][ny] = true;
            board[nx][ny] = '.';
            wq.push({nx,ny, cnt+1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    memset(w_time, -1, sizeof(w_time));

    input();

     while(1){
         can_go();
         sink_2();
     }

    return 0;
}