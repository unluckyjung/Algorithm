#include <bits/stdc++.h>
using namespace std;

int ans = INT_MIN;
int board[501][501];
bool visit[501][501];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int n, m;


void dfs(int x, int y , int cur_cnt, int cur_sum){
    if(cur_cnt == 4){
        ans = max(ans, cur_sum);
        return;
    }
    //visit[x][y] = true;   //1
    //가져온 뒤 확인하는 방식도 가능함.

    for(int dir = 0 ; dir<4; ++dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 or nx >=n or ny <0 or ny >=m)continue;
        if(visit[nx][ny])continue;
        visit[nx][ny] = true;   //2
        dfs(nx, ny, cur_cnt +1, cur_sum + board[nx][ny]);
        visit[nx][ny] = false;  //2
    }
    //visit[x][y] = false;  //1
}

void check(int x, int y){
    int MIN = INT_MAX;
    int sum = board[x][y];
    int cnt = 0;

    for(int dir = 0 ; dir<4; ++dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 or nx >=n or ny <0 or ny >=m)continue;
        cnt ++;
        sum += board[nx][ny];
        MIN = min(MIN, board[nx][ny]);
    }
    if(cnt == 4) sum -= MIN;

    ans = max(ans,sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ; i<n; ++i){
        for(int ii = 0 ; ii <m; ++ii){
            cin >> board[i][ii];
        }
    }

    for(int i = 0 ; i<n; ++i){
        for(int ii = 0 ; ii <m; ++ii){
            visit[i][ii] = true;
            dfs(i, ii, 0, 0);
            visit[i][ii] = false;
            check(i,ii);
        }
    }    

    cout << ans << "\n";
    return 0;
}