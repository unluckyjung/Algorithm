#include <bits/stdc++.h>
using namespace std;

int board[11][11];
bool visit[11];

int answer = INT_MAX;
int start;
int n;

void input(){
    cin >> n;
    for(int i = 0 ; i<n ;++i){
        for(int ii = 0 ; ii < n; ++ii){
            cin >> board[i][ii];
        }
    }
}

void dfs(const int &cur , const int &sum, const int &cnt){
    if(cnt == n && cur == start){
        answer = min(answer , sum);
        return;
    }

    for(int next = 0; next < n; ++next){
        if(visit[next])continue;
        if(board[cur][next] == 0)continue;

        visit[next] = true;
        dfs(next, sum + board[cur][next], cnt+1);
        visit[next] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < n; ++i)
    {   
        start = i;
        dfs(i, 0, 0);
    }

    cout << answer <<"\n";
    return 0;
}