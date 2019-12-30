#include <bits/stdc++.h>
using namespace std;

int n;
int board[11][11];
int B_max, W_max;

bool visit1[30];
bool visit2[30];

void board_set(){
    cin >> n;
    for(int i = 0 ; i<n; ++i){
        for(int ii = 0 ; ii<n; ++ii){
            cin >> board[i][ii];
        }
    }
}

void solve(int nx, int ny, int cnt, int color){
    if(ny>=n){
        nx++;
        ny = 0;
    }

    if(nx >=n){
        if(color)W_max = max(W_max, cnt);
        else B_max = max(B_max, cnt);
        return;
    }

    if(color!= (nx+ny)%2)   ny++;

    
    if(board[nx][ny] && !visit1[nx+ny] && !visit2[nx-ny+n-1]){
        board[nx][ny] = 0;
        visit1[nx+ny] = true;
        visit2[nx-ny+n-1] = true;
        solve(nx, ny+2, cnt+1, color);
        board[nx][ny] = 1;
        visit1[nx+ny] = false;
        visit2[nx-ny+n-1] = false;
    }

    solve(nx, ny+2, cnt, color);

}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    board_set();
    solve(0,0,0,0);
    solve(0,1,0,1);

    cout << B_max + W_max <<"\n";
    return 0;
}