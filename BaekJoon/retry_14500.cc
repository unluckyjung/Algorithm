#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool visit[502][502];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n, m;
int answer = INT_MIN;

void input()
{
    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < m; ++ii)
            cin >> board[i][ii];
    }
}

void dfs(const int &x, const int &y, const int &cnt, const int &sum)
{
    if (cnt == 4)
    {
        answer = max(answer, sum);
        return;
    }

    for(int dir = 0 ; dir<4; ++dir){
        int nx = x+ dx[dir];
        int ny = y+ dy[dir];
        if(nx < 0 or nx >=n or ny <0 or ny >=m )continue;
        if(visit[nx][ny])continue;
        
        visit[nx][ny] = true;
        dfs(nx, ny, cnt + 1, sum + board[nx][ny]);
        visit[nx][ny] = false;
    }

    return;
}

void check(const int &x, const int &y)
{
    int MIN = INT_MAX;
    int sum = board[x][y];
    int cnt = 1;  //1
    //int cnt = 0;    //2
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
        cnt ++;
        sum += board[nx][ny];
        MIN = min(MIN, board[nx][ny]);
    }
    if (cnt == 5)   sum -= MIN; //1
    //if (cnt == 4)   sum -= MIN; //2


    if(cnt >= 4) answer = max(answer, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    input();

    for (int i = 0; i < n; ++i)
    {
        for (int ii = 0; ii < m; ++ii)
        {
            visit[i][ii] = true;
            dfs(i, ii, 1, board[i][ii]);
            //dfs(i, ii, 0, 0);
            visit[i][ii] = false;
            check(i, ii);
        }
    }

    cout << answer <<"\n";

    return 0;
}