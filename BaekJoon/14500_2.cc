#include <bits/stdc++.h>
using namespace std;

int board[501][501];
bool visit[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int answer = INT_MIN;

int n, m;

void input(){
    cin >> n >> m;
    for(int i = 0; i<n; ++i){
        for(int ii = 0 ; ii <m; ++ii){
            cin >> board[i][ii];
        }
    }
}

void dfs(const int &x, const int &y, const int &cnt, const int &sum){
    if(cnt == 4){
        answer = max(answer , sum);
        return;
    }

    if (cnt < 4)
    {
        for(int dir = 0 ; dir<4; ++dir){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(visit[nx][ny])continue;
            if(nx < 0 or nx >=n or ny <0 or ny >=m)continue;

            visit[nx][ny] = true;
            dfs(nx, ny, cnt+1, sum + board[nx][ny]);
            visit[nx][ny] = false;
        }
    }
}

void exception_check(int const &x, int const &y){
    int cnt = 1;
    int sum = board[x][y];
    int MIN = INT_MAX;

    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (visit[nx][ny])continue;
        if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
        MIN = min(MIN, board[nx][ny]);
        sum += board[nx][ny];
        cnt++;
    }
    if (cnt == 5)   sum -= MIN;
    if (cnt >= 4)   answer = max(answer, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);   //제출전 주석처리
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for(int i = 0; i<n; ++i){
        for(int ii = 0 ; ii <m; ++ii){
            visit[i][ii] = true;
            dfs(i, ii , 1, board[i][ii]);
            visit[i][ii] = false;
            exception_check(i, ii);
        }
    }

    cout << answer << "\n";
    return 0;
}